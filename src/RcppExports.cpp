// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// compute_adt_qc_metrics
Rcpp::List compute_adt_qc_metrics(SEXP x, Rcpp::List subsets, int num_threads);
RcppExport SEXP _scrapper_compute_adt_qc_metrics(SEXP xSEXP, SEXP subsetsSEXP, SEXP num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type subsets(subsetsSEXP);
    Rcpp::traits::input_parameter< int >::type num_threads(num_threadsSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_adt_qc_metrics(x, subsets, num_threads));
    return rcpp_result_gen;
END_RCPP
}
// suggest_adt_qc_thresholds
Rcpp::List suggest_adt_qc_thresholds(Rcpp::List metrics, Rcpp::Nullable<Rcpp::IntegerVector> block, double min_detected_drop, double num_mads);
RcppExport SEXP _scrapper_suggest_adt_qc_thresholds(SEXP metricsSEXP, SEXP blockSEXP, SEXP min_detected_dropSEXP, SEXP num_madsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type metrics(metricsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    Rcpp::traits::input_parameter< double >::type min_detected_drop(min_detected_dropSEXP);
    Rcpp::traits::input_parameter< double >::type num_mads(num_madsSEXP);
    rcpp_result_gen = Rcpp::wrap(suggest_adt_qc_thresholds(metrics, block, min_detected_drop, num_mads));
    return rcpp_result_gen;
END_RCPP
}
// filter_adt_qc_metrics
Rcpp::LogicalVector filter_adt_qc_metrics(Rcpp::List filters, Rcpp::List metrics, Rcpp::Nullable<Rcpp::IntegerVector> block);
RcppExport SEXP _scrapper_filter_adt_qc_metrics(SEXP filtersSEXP, SEXP metricsSEXP, SEXP blockSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type filters(filtersSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type metrics(metricsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    rcpp_result_gen = Rcpp::wrap(filter_adt_qc_metrics(filters, metrics, block));
    return rcpp_result_gen;
END_RCPP
}
// aggregate_across_cells
SEXP aggregate_across_cells(SEXP x, Rcpp::IntegerVector combined, int nthreads);
RcppExport SEXP _scrapper_aggregate_across_cells(SEXP xSEXP, SEXP combinedSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type combined(combinedSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(aggregate_across_cells(x, combined, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// center_size_factors
Rcpp::NumericVector center_size_factors(Rcpp::NumericVector size_factors, Rcpp::Nullable<Rcpp::IntegerVector> block, bool lowest);
RcppExport SEXP _scrapper_center_size_factors(SEXP size_factorsSEXP, SEXP blockSEXP, SEXP lowestSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type size_factors(size_factorsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    Rcpp::traits::input_parameter< bool >::type lowest(lowestSEXP);
    rcpp_result_gen = Rcpp::wrap(center_size_factors(size_factors, block, lowest));
    return rcpp_result_gen;
END_RCPP
}
// choose_highly_variable_genes
Rcpp::IntegerVector choose_highly_variable_genes(Rcpp::NumericVector stats, int top, bool larger, bool keep_ties);
RcppExport SEXP _scrapper_choose_highly_variable_genes(SEXP statsSEXP, SEXP topSEXP, SEXP largerSEXP, SEXP keep_tiesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type stats(statsSEXP);
    Rcpp::traits::input_parameter< int >::type top(topSEXP);
    Rcpp::traits::input_parameter< bool >::type larger(largerSEXP);
    Rcpp::traits::input_parameter< bool >::type keep_ties(keep_tiesSEXP);
    rcpp_result_gen = Rcpp::wrap(choose_highly_variable_genes(stats, top, larger, keep_ties));
    return rcpp_result_gen;
END_RCPP
}
// choose_pseudo_count
double choose_pseudo_count(Rcpp::NumericVector size_factors, double quantile, double max_bias, double min_value);
RcppExport SEXP _scrapper_choose_pseudo_count(SEXP size_factorsSEXP, SEXP quantileSEXP, SEXP max_biasSEXP, SEXP min_valueSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type size_factors(size_factorsSEXP);
    Rcpp::traits::input_parameter< double >::type quantile(quantileSEXP);
    Rcpp::traits::input_parameter< double >::type max_bias(max_biasSEXP);
    Rcpp::traits::input_parameter< double >::type min_value(min_valueSEXP);
    rcpp_result_gen = Rcpp::wrap(choose_pseudo_count(size_factors, quantile, max_bias, min_value));
    return rcpp_result_gen;
END_RCPP
}
// combine_factors
Rcpp::List combine_factors(Rcpp::List factors, bool keep_unused, Rcpp::IntegerVector nlevels);
RcppExport SEXP _scrapper_combine_factors(SEXP factorsSEXP, SEXP keep_unusedSEXP, SEXP nlevelsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type factors(factorsSEXP);
    Rcpp::traits::input_parameter< bool >::type keep_unused(keep_unusedSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type nlevels(nlevelsSEXP);
    rcpp_result_gen = Rcpp::wrap(combine_factors(factors, keep_unused, nlevels));
    return rcpp_result_gen;
END_RCPP
}
// compute_crispr_qc_metrics
Rcpp::List compute_crispr_qc_metrics(SEXP x, int num_threads);
RcppExport SEXP _scrapper_compute_crispr_qc_metrics(SEXP xSEXP, SEXP num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type num_threads(num_threadsSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_crispr_qc_metrics(x, num_threads));
    return rcpp_result_gen;
END_RCPP
}
// suggest_crispr_qc_thresholds
Rcpp::List suggest_crispr_qc_thresholds(Rcpp::List metrics, Rcpp::Nullable<Rcpp::IntegerVector> block, double min_detected_drop, double num_mads);
RcppExport SEXP _scrapper_suggest_crispr_qc_thresholds(SEXP metricsSEXP, SEXP blockSEXP, SEXP min_detected_dropSEXP, SEXP num_madsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type metrics(metricsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    Rcpp::traits::input_parameter< double >::type min_detected_drop(min_detected_dropSEXP);
    Rcpp::traits::input_parameter< double >::type num_mads(num_madsSEXP);
    rcpp_result_gen = Rcpp::wrap(suggest_crispr_qc_thresholds(metrics, block, min_detected_drop, num_mads));
    return rcpp_result_gen;
END_RCPP
}
// filter_crispr_qc_metrics
Rcpp::LogicalVector filter_crispr_qc_metrics(Rcpp::List filters, Rcpp::List metrics, Rcpp::Nullable<Rcpp::IntegerVector> block);
RcppExport SEXP _scrapper_filter_crispr_qc_metrics(SEXP filtersSEXP, SEXP metricsSEXP, SEXP blockSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type filters(filtersSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type metrics(metricsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    rcpp_result_gen = Rcpp::wrap(filter_crispr_qc_metrics(filters, metrics, block));
    return rcpp_result_gen;
END_RCPP
}
// fit_variance_trend
Rcpp::List fit_variance_trend(Rcpp::NumericVector means, Rcpp::NumericVector variances, bool mean_filter, double min_mean, bool transform, double span, bool use_min_width, double min_width, int min_window_count, int num_threads);
RcppExport SEXP _scrapper_fit_variance_trend(SEXP meansSEXP, SEXP variancesSEXP, SEXP mean_filterSEXP, SEXP min_meanSEXP, SEXP transformSEXP, SEXP spanSEXP, SEXP use_min_widthSEXP, SEXP min_widthSEXP, SEXP min_window_countSEXP, SEXP num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type means(meansSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type variances(variancesSEXP);
    Rcpp::traits::input_parameter< bool >::type mean_filter(mean_filterSEXP);
    Rcpp::traits::input_parameter< double >::type min_mean(min_meanSEXP);
    Rcpp::traits::input_parameter< bool >::type transform(transformSEXP);
    Rcpp::traits::input_parameter< double >::type span(spanSEXP);
    Rcpp::traits::input_parameter< bool >::type use_min_width(use_min_widthSEXP);
    Rcpp::traits::input_parameter< double >::type min_width(min_widthSEXP);
    Rcpp::traits::input_parameter< int >::type min_window_count(min_window_countSEXP);
    Rcpp::traits::input_parameter< int >::type num_threads(num_threadsSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_variance_trend(means, variances, mean_filter, min_mean, transform, span, use_min_width, min_width, min_window_count, num_threads));
    return rcpp_result_gen;
END_RCPP
}
// model_gene_variances
Rcpp::List model_gene_variances(SEXP x, Rcpp::Nullable<Rcpp::IntegerVector> block, size_t nblocks, std::string block_weight_policy, Rcpp::NumericVector variable_block_weight, bool mean_filter, double min_mean, bool transform, double span, bool use_min_width, double min_width, int min_window_count, int num_threads);
RcppExport SEXP _scrapper_model_gene_variances(SEXP xSEXP, SEXP blockSEXP, SEXP nblocksSEXP, SEXP block_weight_policySEXP, SEXP variable_block_weightSEXP, SEXP mean_filterSEXP, SEXP min_meanSEXP, SEXP transformSEXP, SEXP spanSEXP, SEXP use_min_widthSEXP, SEXP min_widthSEXP, SEXP min_window_countSEXP, SEXP num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    Rcpp::traits::input_parameter< size_t >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_weight_policy(block_weight_policySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type variable_block_weight(variable_block_weightSEXP);
    Rcpp::traits::input_parameter< bool >::type mean_filter(mean_filterSEXP);
    Rcpp::traits::input_parameter< double >::type min_mean(min_meanSEXP);
    Rcpp::traits::input_parameter< bool >::type transform(transformSEXP);
    Rcpp::traits::input_parameter< double >::type span(spanSEXP);
    Rcpp::traits::input_parameter< bool >::type use_min_width(use_min_widthSEXP);
    Rcpp::traits::input_parameter< double >::type min_width(min_widthSEXP);
    Rcpp::traits::input_parameter< int >::type min_window_count(min_window_countSEXP);
    Rcpp::traits::input_parameter< int >::type num_threads(num_threadsSEXP);
    rcpp_result_gen = Rcpp::wrap(model_gene_variances(x, block, nblocks, block_weight_policy, variable_block_weight, mean_filter, min_mean, transform, span, use_min_width, min_width, min_window_count, num_threads));
    return rcpp_result_gen;
END_RCPP
}
// normalize_counts
SEXP normalize_counts(SEXP x, Rcpp::NumericVector size_factors, bool log, double pseudo_count, double log_base, bool preserve_sparsity);
RcppExport SEXP _scrapper_normalize_counts(SEXP xSEXP, SEXP size_factorsSEXP, SEXP logSEXP, SEXP pseudo_countSEXP, SEXP log_baseSEXP, SEXP preserve_sparsitySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type size_factors(size_factorsSEXP);
    Rcpp::traits::input_parameter< bool >::type log(logSEXP);
    Rcpp::traits::input_parameter< double >::type pseudo_count(pseudo_countSEXP);
    Rcpp::traits::input_parameter< double >::type log_base(log_baseSEXP);
    Rcpp::traits::input_parameter< bool >::type preserve_sparsity(preserve_sparsitySEXP);
    rcpp_result_gen = Rcpp::wrap(normalize_counts(x, size_factors, log, pseudo_count, log_base, preserve_sparsity));
    return rcpp_result_gen;
END_RCPP
}
// compute_rna_qc_metrics
Rcpp::List compute_rna_qc_metrics(SEXP x, Rcpp::List subsets, int num_threads);
RcppExport SEXP _scrapper_compute_rna_qc_metrics(SEXP xSEXP, SEXP subsetsSEXP, SEXP num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type subsets(subsetsSEXP);
    Rcpp::traits::input_parameter< int >::type num_threads(num_threadsSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_rna_qc_metrics(x, subsets, num_threads));
    return rcpp_result_gen;
END_RCPP
}
// suggest_rna_qc_thresholds
Rcpp::List suggest_rna_qc_thresholds(Rcpp::List metrics, Rcpp::Nullable<Rcpp::IntegerVector> block, double min_detected_drop, double num_mads);
RcppExport SEXP _scrapper_suggest_rna_qc_thresholds(SEXP metricsSEXP, SEXP blockSEXP, SEXP min_detected_dropSEXP, SEXP num_madsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type metrics(metricsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    Rcpp::traits::input_parameter< double >::type min_detected_drop(min_detected_dropSEXP);
    Rcpp::traits::input_parameter< double >::type num_mads(num_madsSEXP);
    rcpp_result_gen = Rcpp::wrap(suggest_rna_qc_thresholds(metrics, block, min_detected_drop, num_mads));
    return rcpp_result_gen;
END_RCPP
}
// filter_rna_qc_metrics
Rcpp::LogicalVector filter_rna_qc_metrics(Rcpp::List filters, Rcpp::List metrics, Rcpp::Nullable<Rcpp::IntegerVector> block);
RcppExport SEXP _scrapper_filter_rna_qc_metrics(SEXP filtersSEXP, SEXP metricsSEXP, SEXP blockSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type filters(filtersSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type metrics(metricsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    rcpp_result_gen = Rcpp::wrap(filter_rna_qc_metrics(filters, metrics, block));
    return rcpp_result_gen;
END_RCPP
}
// run_pca
Rcpp::List run_pca(SEXP x, int number, Rcpp::Nullable<Rcpp::IntegerVector> block, std::string block_weight_policy, Rcpp::NumericVector variable_block_weight, bool components_from_residuals, bool scale, bool realized, int irlba_work, int irlba_iterations, int irlba_seed, int num_threads);
RcppExport SEXP _scrapper_run_pca(SEXP xSEXP, SEXP numberSEXP, SEXP blockSEXP, SEXP block_weight_policySEXP, SEXP variable_block_weightSEXP, SEXP components_from_residualsSEXP, SEXP scaleSEXP, SEXP realizedSEXP, SEXP irlba_workSEXP, SEXP irlba_iterationsSEXP, SEXP irlba_seedSEXP, SEXP num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type number(numberSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::IntegerVector> >::type block(blockSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_weight_policy(block_weight_policySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type variable_block_weight(variable_block_weightSEXP);
    Rcpp::traits::input_parameter< bool >::type components_from_residuals(components_from_residualsSEXP);
    Rcpp::traits::input_parameter< bool >::type scale(scaleSEXP);
    Rcpp::traits::input_parameter< bool >::type realized(realizedSEXP);
    Rcpp::traits::input_parameter< int >::type irlba_work(irlba_workSEXP);
    Rcpp::traits::input_parameter< int >::type irlba_iterations(irlba_iterationsSEXP);
    Rcpp::traits::input_parameter< int >::type irlba_seed(irlba_seedSEXP);
    Rcpp::traits::input_parameter< int >::type num_threads(num_threadsSEXP);
    rcpp_result_gen = Rcpp::wrap(run_pca(x, number, block, block_weight_policy, variable_block_weight, components_from_residuals, scale, realized, irlba_work, irlba_iterations, irlba_seed, num_threads));
    return rcpp_result_gen;
END_RCPP
}
// sanitize_size_factors
Rcpp::NumericVector sanitize_size_factors(Rcpp::NumericVector size_factors, bool handle_zero, bool handle_negative, bool handle_nan, bool handle_infinite);
RcppExport SEXP _scrapper_sanitize_size_factors(SEXP size_factorsSEXP, SEXP handle_zeroSEXP, SEXP handle_negativeSEXP, SEXP handle_nanSEXP, SEXP handle_infiniteSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type size_factors(size_factorsSEXP);
    Rcpp::traits::input_parameter< bool >::type handle_zero(handle_zeroSEXP);
    Rcpp::traits::input_parameter< bool >::type handle_negative(handle_negativeSEXP);
    Rcpp::traits::input_parameter< bool >::type handle_nan(handle_nanSEXP);
    Rcpp::traits::input_parameter< bool >::type handle_infinite(handle_infiniteSEXP);
    rcpp_result_gen = Rcpp::wrap(sanitize_size_factors(size_factors, handle_zero, handle_negative, handle_nan, handle_infinite));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_scrapper_compute_adt_qc_metrics", (DL_FUNC) &_scrapper_compute_adt_qc_metrics, 3},
    {"_scrapper_suggest_adt_qc_thresholds", (DL_FUNC) &_scrapper_suggest_adt_qc_thresholds, 4},
    {"_scrapper_filter_adt_qc_metrics", (DL_FUNC) &_scrapper_filter_adt_qc_metrics, 3},
    {"_scrapper_aggregate_across_cells", (DL_FUNC) &_scrapper_aggregate_across_cells, 3},
    {"_scrapper_center_size_factors", (DL_FUNC) &_scrapper_center_size_factors, 3},
    {"_scrapper_choose_highly_variable_genes", (DL_FUNC) &_scrapper_choose_highly_variable_genes, 4},
    {"_scrapper_choose_pseudo_count", (DL_FUNC) &_scrapper_choose_pseudo_count, 4},
    {"_scrapper_combine_factors", (DL_FUNC) &_scrapper_combine_factors, 3},
    {"_scrapper_compute_crispr_qc_metrics", (DL_FUNC) &_scrapper_compute_crispr_qc_metrics, 2},
    {"_scrapper_suggest_crispr_qc_thresholds", (DL_FUNC) &_scrapper_suggest_crispr_qc_thresholds, 4},
    {"_scrapper_filter_crispr_qc_metrics", (DL_FUNC) &_scrapper_filter_crispr_qc_metrics, 3},
    {"_scrapper_fit_variance_trend", (DL_FUNC) &_scrapper_fit_variance_trend, 10},
    {"_scrapper_model_gene_variances", (DL_FUNC) &_scrapper_model_gene_variances, 13},
    {"_scrapper_normalize_counts", (DL_FUNC) &_scrapper_normalize_counts, 6},
    {"_scrapper_compute_rna_qc_metrics", (DL_FUNC) &_scrapper_compute_rna_qc_metrics, 3},
    {"_scrapper_suggest_rna_qc_thresholds", (DL_FUNC) &_scrapper_suggest_rna_qc_thresholds, 4},
    {"_scrapper_filter_rna_qc_metrics", (DL_FUNC) &_scrapper_filter_rna_qc_metrics, 3},
    {"_scrapper_run_pca", (DL_FUNC) &_scrapper_run_pca, 12},
    {"_scrapper_sanitize_size_factors", (DL_FUNC) &_scrapper_sanitize_size_factors, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_scrapper(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
