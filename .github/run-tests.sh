#!/bin/sh
cd ../interval_operations/src && ./compile.sh 
cd ../../
rm -rf build && mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
./unit_tests >> test_results.txt
grep -Ri "fail" test_results.txt
