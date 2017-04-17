#include <Rcpp.h>
#include <vector>
#include <thrust/device_vector.h>
#include "myHeader.h"
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector myCppF(NumericVector Rx) {
  std::vector<double> x_h = Rcpp::as<std::vector<double> >(Rx);
  thrust::device_vector<double> x_d(x_h.begin(), x_h.end());
  myOp(x_d);
  thrust::copy(x_d.begin(), x_d.end(), x_h.begin());
  return Rx;
}
