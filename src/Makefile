NVCC_FLAGS = -arch=sm_35 -Xcompiler -fPIC

DEBUG_FLAGS = -DTHRUST_DEBUG

R_INC = ${R_HOME}/include

CUDA_PATH = /usr/local/cuda-8.0/lib64

LIBS = -lcublas_device -lcublas -lcurand -lcuda -lcudart

TARGET = RcppThrust.so

#final SHLIB
$(TARGET): myWrapper.cpp mySource.o
	nvcc -shared $(NVCC_FLAGS) -o $(TARGET) -I$(R_INC) -I. $(DEBUG_FLAGS)

#wrappers
mySource.o: mySource.cu
	nvcc -c $(NVCC_FLAGS) $< -o $@ $(LIBS)

