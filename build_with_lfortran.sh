mkdir build
cd build

FC="/Users/gxyd/OpenSource/lfortran/src/bin/lfortran" cmake .. -DCMAKE_TOOLCHAIN_FILE=../toolchain-lfortran.cmake

make tests VERBOSE=1

