#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector calc_I_1(NumericMatrix X, int steps, float dt) {
  int i;
  NumericVector I;
  I = X(_, steps)/2 * steps * dt * dt;
  for(i = 1; i < steps; i++) {
    I = I + X(_, i) * (i * dt) * dt;
    }
  return I;
}
