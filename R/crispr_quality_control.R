#' Quality control for CRISPR count data
#'
#' Compute per-cell QC metrics from an initialized matrix of CRISPR counts,
#' and use the metrics to suggest filter thresholds to retain high-quality cells.
#' 
#' @param x A matrix-like object where rows are CRISPRs and columns are cells.
#' Values are expected to be counts.
#' @param num.threads Integer scalar specifying the number of threads to use.
#' @param metrics List with the same structure as produced by \code{computeCrisprQcMetrics}.
#' @param block Factor specifying the block of origin (e.g., batch, sample) for each cell in \code{metrics}.
#' Alternatively \code{NULL} if all cells are from the same block.
#'
#' For \code{filterCrisprQcMetrics}, a blocking factor should be provided if \code{block} was used to construct \code{thresholds}. 
#' @param num.mads Number of median from the median, to define the threshold for outliers in each metric.
#' @param thresholds List with the same structure as produced by \code{suggestCrisprQcThresholds}.
#'
#' @return For \code{computeCrisprQcMetrics}, a list is returned containing:
#' \itemize{
#' \item \code{sum}, a numeric vector containing the total CRISPR count for each cell.
#' \item \code{detected}, an integer vector containing the number of detected guides per cell.
#' \item \code{max.value}, a numeric vector containing the count for the most abundant guide in cell.
#' \item \code{max.index}, an integer vector containing the row index of the most abundant guide in cell.
#' }
#' Each vector is of length equal to the number of cells.
#'
#' For \code{suggestCrisprQcThresholds}, a named list is returned.
#' \itemize{
#' \item If \code{block=NULL}, the list contains:
#' \itemize{
#' \item \code{max.value}, a numeric scalar containing the lower bound on the maximum counts for each blocking level.
#' }
#' \item Otherwise, if \code{block} is supplied, the list contains:
#' \itemize{
#' \item \code{max.value}, a numeric vector containing the lower bound on the maximum counts for each blocking level.
#' }
#' Each vector is of length equal to the number of levels in \code{block} and is named accordingly.
#' }
#'
#' For \code{filterCrisprQcMetrics}, a logical vector of length \code{ncol(x)} is returned indicating which cells are of high quality. 
#'
#' @seealso
#' The \code{compute_crispr_qc_metrics}, \code{compute_crispr_qc_filters} and \code{compute_crispr_qc_filters_blocked} functions in \url{https://libscran.github.io/scran_qc/},
#' for the rationale of QC filtering on CRISPR counts.
#'
#' @author Aaron Lun
#' @examples
#' # Mocking a matrix:
#' library(Matrix)
#' x <- round(abs(rsparsematrix(100, 100, 0.1) * 100))
#'
#' qc <- computeCrisprQcMetrics(x)
#' str(qc)
#'
#' filt <- suggestCrisprQcThresholds(qc)
#' str(filt)
#'
#' keep <- filterCrisprQcMetrics(filt, qc)
#' summary(keep)
#'
#' @export
#' @name crispr_quality_control
computeCrisprQcMetrics <- function(x, num.threads = 1) {
    y <- initializeCpp(x, .check.na=FALSE)
    output <- compute_crispr_qc_metrics(y, num_threads=num.threads)
    output$max.index <- output$max.index + 1L
    output
}

#' @export
#' @rdname crispr_quality_control
suggestCrisprQcThresholds <- function(metrics, block=NULL, num.mads=3) {
    block <- .transformFactor(block)
    metrics$max.index <- metrics$max.index - 1L # restore 0-based indexing.
    thresholds <- suggest_crispr_qc_thresholds(metrics, block=block$index, num_mads=num.mads)
    names(thresholds$max.value) <- block$names
    thresholds
}

#' @export
#' @rdname crispr_quality_control
filterCrisprQcMetrics <- function(thresholds, metrics, block=NULL) {
    block <- .matchBlock(block, names(thresholds$max.value))
    metrics$max.index <- metrics$max.index - 1L # restore 0-based indexing.
    filter_crispr_qc_metrics(thresholds, metrics, block=block)
}
