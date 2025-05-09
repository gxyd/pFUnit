mkdir -p build && cd build

cmake .. -DCMAKE_Fortran_COMPILER=$(which gfortran)

make -j$(sysctl -n hw.logicalcpu)
