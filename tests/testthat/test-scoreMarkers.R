# library(testthat); library(scrapper); source("test-scoreMarkers.R")

set.seed(999)
library(Matrix)
x <- abs(rsparsematrix(1000, 100, 0.1))
x@x <- jitter(x@x)

check_summaries <- function(summary) {
    for (x in names(summary)) {
        current <- summary[[x]]
        expect_true(all(current$min <= current$max))
        expect_true(all(current$min <= current$mean + 1e-8)) # add some tolerance for numerical imprecision when averaging identical effects.
        expect_true(all(current$min <= current$median))
        expect_true(all(current$mean <= current$max + 1e-8))
        expect_true(all(current$median <= current$max))
        expect_true(all(current$min_rank <= 1000))
        expect_true(all(current$min_rank > 0))
    }
}

test_that("scoreMarkers works as expected for simple cases", {
    g <- sample(letters[1:4], ncol(x), replace=TRUE)
    out <- scoreMarkers(x, g)

    expect_equal(out$mean[,"a"], Matrix::rowMeans(x[,g=="a"]))
    expect_equal(out$detected[,"d"], Matrix::rowMeans(x[,g=="d"] > 0))

    check_summaries(out$cohens.d)
    check_summaries(out$auc)
    check_summaries(out$delta.mean)
    check_summaries(out$delta.detected)

    for (n in names(out$auc)) {
        collected <- unlist(out$auc[[n]][c("min", "mean", "median", "max")])
        expect_true(all(collected >= 0))
        expect_true(all(collected <= 1))
    }

    # Same results for multiple threads.
    pout <- scoreMarkers(x, g, num.threads=2)
    expect_identical(out, pout)

    # Works without the AUC.
    aout <- scoreMarkers(x, g, compute.auc=FALSE)
    expect_false("auc" %in% names(aout))
    expect_equal(out$mean, aout$mean)
    expect_equal(out$delta.detected, aout$delta.detected)

    # Works without anything.
    empty <- scoreMarkers(x, g, compute.auc=FALSE, compute.cohens.d=FALSE, compute.delta.detected=FALSE, compute.delta.mean=FALSE)
    expect_identical(names(empty), c("mean", "detected"))
})

test_that("scoreMarkers works with blocking", {
    g <- sample(letters[1:4], ncol(x), replace=TRUE)
    b <- rep(1:3, length.out=ncol(x))
    out <- scoreMarkers(x, g, block=b, block.weight.policy="equal")

    bkeep <- g == "b"
    expect_equal(out$mean[,"b"], (Matrix::rowMeans(x[,bkeep & b == 1]) + Matrix::rowMeans(x[,bkeep & b == 2]) + Matrix::rowMeans(x[,bkeep & b == 3]))/3)
    ckeep <- g == "c"
    expect_equal(out$mean[,"c"], (Matrix::rowMeans(x[,ckeep & b == 1]) + Matrix::rowMeans(x[,ckeep & b == 2]) + Matrix::rowMeans(x[,ckeep & b == 3]))/3)

    check_summaries(out$cohens.d)
    check_summaries(out$auc)
    check_summaries(out$delta.mean)
    check_summaries(out$delta.detected)

    for (x in names(out$auc)) {
        collected <- unlist(out$auc[[x]][c("min", "mean", "median", "max")])
        expect_true(all(collected >= 0))
        expect_true(all(collected <= 1))
    }
})

test_that("scoreMarkers works as expected for the full pairwise statistics", {
    g <- sample(4, ncol(x), replace=TRUE)
    full <- scoreMarkers(x, g, all.pairwise=TRUE)

    # Checking that we set the dimensions correctly.
    for (g1 in seq_len(4)) {
        for (g2 in seq_len(g1)) {
            if (g1 == g2) {
                expect_true(all(full$delta.mean[g1, g2, ] == 0))
                expect_true(all(full$auc[g1, g2, ] == 0))
            } else {
                expect_equal(full$delta.mean[g1, g2, ], -full$delta.mean[g2, g1, ])
                expect_equal(full$auc[g1, g2, ], 1 - full$auc[g2, g1, ])
            }
        }
    }

    expect_true(all(full$auc >= 0))
    expect_true(all(full$auc <= 1))

    # Works without AUCs.
    aout <- scoreMarkers(x, g, all.pairwise=TRUE, compute.auc=FALSE)
    expect_false("auc" %in% names(aout))
    expect_equal(full$detected, aout$detected)
    expect_equal(full$cohens.d, aout$cohens.d)

    # Works without anything.
    empty <- scoreMarkers(x, g, compute.auc=FALSE, compute.cohens.d=FALSE, compute.delta.detected=FALSE, compute.delta.mean=FALSE)
    expect_identical(names(empty), c("mean", "detected"))

    # Works with blocking.
    b <- rep(1:3, length.out=ncol(x))
    bout <- scoreMarkers(x, g, block=b, block.weight.policy="equal", all.pairwise=TRUE)
    sbout <- scoreMarkers(x, g, block=b, block.weight.policy="equal")
    expect_identical(bout$mean, sbout$mean)
})

test_that("reportGroupMarkerStatistics works as expected", {
    g <- sample(letters[1:4], ncol(x), replace=TRUE)
    out <- scoreMarkers(x, g)

    df <- reportGroupMarkerStatistics(out, "b")
    expect_identical(length(df$mean), nrow(x))
    expect_identical(length(df$detected), nrow(x))
    expect_identical(length(df$cohens.d.min), nrow(x))
    expect_identical(length(df$auc.median), nrow(x))
    expect_identical(length(df$delta.mean.min.rank), nrow(x))
    expect_identical(length(df$delta.detected.max), nrow(x))

    df <- reportGroupMarkerStatistics(out, 3, include.mean=FALSE, include.detected=FALSE, effect.sizes=character(0), summaries=character(0))
    expect_identical(nrow(df), nrow(x))
    expect_identical(ncol(df), 0L)

    # Works with row names and missing statistics.
    rownames(x) <- sprintf("GENE_%i", seq_len(nrow(x)))
    out <- scoreMarkers(x, g, compute.auc=FALSE)
    df <- reportGroupMarkerStatistics(out, 1)
    expect_identical(rownames(df), rownames(x))
    expect_null(df$auc.median)
})
