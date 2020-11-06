# do the query test and check correctness
if [ ! -d "build" ] 
then
    mkdir build
fi
cd build
rm queries.txt
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
./tests/query >> queries.txt
cd ..
cd mathmetica_notebooks
./verify_queries ../build/queries.txt errors_"$OSTYPE".txt
cd ..