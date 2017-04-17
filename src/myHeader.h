#include <thrust/device_vector.h>
#include <thrust/scan.h>
#include <thrust/execution_policy.h>

void myOp(thrust::device_vector<double> &x);
