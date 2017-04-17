#include <Rcpp.h>
#include <vector>
#include <iostream>
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include "myHeader.h"
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector myCppF(NumericVector Rx) {
  std::vector<double> x_h = Rcpp::as<std::vector<double> >(Rx);
  thrust::device_vector<double> x_d(x_h.begin(), x_h.end());
  myOp(x_d);
  thrust::copy(x_d.begin(), x_d.end(), x_h.begin());
  for(int i=0; i<x_h.size(); i++)
    std::cout << "" << x_h[i];
  std::cout <<"\n";
  NumericVector Rout = wrap(x_h);
  return Rout;
}
