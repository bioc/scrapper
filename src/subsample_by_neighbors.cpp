//#include "config.h"

#include "nenesub/nenesub.hpp"
#include "Rcpp.h"
#include "tatami/tatami.hpp"

//[[Rcpp::export(rng=false)]]
SEXP subsample_by_neighbors(Rcpp::IntegerMatrix indices, Rcpp::NumericMatrix distances, int min_remaining) {
    int num_obs = distances.cols();
    size_t k = distances.rows();
    if (static_cast<size_t>(indices.rows()) != k || static_cast<int>(indices.cols()) != num_obs) {
        throw std::runtime_error("'indices' and 'distances' must have the same dimensions");
    }

    if (k < static_cast<size_t>(min_remaining)) {
        throw std::runtime_error("'min_remaining' should not be greater than the number of neighbors");
    }

    const int* iptr = indices.begin();
    const double* dptr = distances.begin();

    nenesub::Options opt;
    opt.min_remaining = min_remaining;
    std::vector<int> selected;
    nenesub::compute(
        indices.cols(),
        /* get_neighbors = */ [&](size_t i) -> tatami::ArrayView<int> {
            return tatami::ArrayView<int>(iptr + k * i, k);
        },
        /* get_index = */ [](const tatami::ArrayView<int>& neighbors, size_t i) -> int {
            return neighbors[i] - 1;
        },
        /* get_max_distance = */ [&](size_t i) -> double {
            return dptr[k * i];
        },
        opt, 
        selected
    );

    for (auto& s : selected) {
        ++s;
    }
    return Rcpp::IntegerVector(selected.begin(), selected.end());
}
