#include "myHeader.h"

void myOp(thrust::device_vector<double> &x){
  thrust::inclusive_scan(thrust::device, x.begin(), x.end(), x.begin());
}
