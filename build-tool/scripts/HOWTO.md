# Build instructions

## For armnn


```
# For BSP 8_02
export PSDKL_PATH=/data/TI/tda4/8_02/vb4/ti-processor-sdk-linux-j7-evm-08_02_00_03
export PSDKL_COMPILER=aarch64-linux

## For BSP 9_00
#export PSDKL_PATH=/data/TI/tda4/9_00/vb4/ti-processor-sdk-linux
#export PSDKL_COMPILER=aarch64-oe-linux

cd armnn
mkdir build
cd build
../build-tool/scripts/setup-armnn.sh --target-arch=aarch64 --tflite-parser
../build-tool/scripts/build-armnn.sh --target-arch=aarch64 --tflite-parser --neon-backend --acl-scons-params="toolchain_prefix=$PSDKL_COMPILER-,compiler_prefix=$PSDKL_COMPILER-,openmp=0,cppthreads=0"

export SYSROOT=$PWD/sysroot
mkdir -p $SYSROOT

DESTDIR=$SYSROOT cmake --install ./build/armnn/aarch64_build --prefix /usr/

# rsync ACL
rsync -avP ./build/acl/aarch64_build/install/* $SYSROOT/usr/
```

## ONNX Runtime

```
cd ../../onnxruntime
bash
source $SDK_ENV_FILE
/build.sh --use_armnn --skip_tests --cmake_extra_defines=CMAKE_TOOLCHAIN_FILE=/data/TI/tda4/9_00/vb4/ti-processor-sdk-linux/linux-devkit/sysroots/x86_64-arago-linux/usr/share/cmake/OEToolchainConfig.cmake --parallel=0
```
