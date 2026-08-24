# Structured Singular Value ($`\mu`$) calculation
Interface to structured singular value (mu) computation

## Build Instructions
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=$(pwd)/install -DSLICOT_DIR=/Users/josiah/SLICOT-Reference/build/install/lib/cmake/SLICOT -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
ctest
```
