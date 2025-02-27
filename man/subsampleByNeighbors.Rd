% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/subsampleByNeighbors.R
\name{subsampleByNeighbors}
\alias{subsampleByNeighbors}
\title{Subsample cells based on their neighbors}
\usage{
subsampleByNeighbors(
  x,
  num.neighbors = 20,
  min.remaining = 10,
  num.threads = 1,
  BNPARAM = AnnoyParam()
)
}
\arguments{
\item{x}{A numeric matrix where rows are dimensions and columns are cells,
typically containing a low-dimensional representation from, e.g., \code{\link{runPca}}.

Alternatively, an index constructed by \code{\link[BiocNeighbors]{buildIndex}}.

Alternatively, a list containing existing nearest-neighbor search results.
This should contain:
\itemize{
\item \code{index}, an integer matrix where rows are neighbors and columns are cells.
Each column contains 1-based indices for the nearest neighbors of the corresponding cell, ordered by increasing distance.
\item \code{distance}, a numeric matrix of the same dimensions as \code{index},
containing the distances to each of the nearest neighbors.
}
The number of neighbors should be equal to \code{num.neighbors}, otherwise a warning is raised.}

\item{num.neighbors}{Integer scalar specifying the number of neighbors to use.
Larger values result in greater downsampling. 
Only used if \code{x} does not contain existing nearest-neighbor results.}

\item{min.remaining}{Integer scalar specifying the minimum number of remaining (i.e., unselected) neighbors that a cell must have in order to be considered for selection.
This should be less than or equal to \code{num.neighbors}.}

\item{num.threads}{Integer scalar specifying the number of threads to use for the nearest-neighbor search.
Only used if \code{x} does not contain existing nearest-neighbor results.}

\item{BNPARAM}{A \link[BiocNeighbors]{BiocNeighborParam} object specifying the algorithm to use.
Only used if \code{x} does not contain existing nearest-neighbor results.}
}
\value{
Integer vector with the indices of the selected cells in the subsample.
}
\description{
Subsample a dataset by selecting cells to represent all of their nearest neighbors.
}
\examples{
x <- matrix(rnorm(10000), nrow=2)
keep <- subsampleByNeighbors(x, 10)
plot(x[1,], x[2,])
points(x[1,keep], x[2,keep], col="red")
legend('topright', col=c('black', 'red'), legend=c('all', 'subsample'), pch=1)

}
\seealso{
\url{https://libscran.github.io/nenesub/}, for more details on the underlying algorithm.
}
\author{
Aaron Lun
}
