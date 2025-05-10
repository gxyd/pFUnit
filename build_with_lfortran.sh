mkdir build
cd build

FC="/Users/gxyd/OpenSource/lfortran/src/bin/lfortran --no-warnings --no-style-warnings" cmake .. -DCMAKE_TOOLCHAIN_FILE=../toolchain-lfortran.cmake

make tests VERBOSE=1

