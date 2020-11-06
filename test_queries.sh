# do the query test and check correctness
if [ ! -d "build" ] 
then
    mkdir build
fi
cd build
rm queries.txt
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
./tests/query_bin >> queries.txt
cd ..
cd mathmetica_notebooks
./verify_queries.wls ../build/queries.txt errors_"$OSTYPE".txt
cd ..