# do the gap test and plot the distribution of gap size vs the base (default filib c version)
if [ ! -d "build" ] 
then
    mkdir build
fi
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
./tests/speed >> time.txt
cd ..
python deal_time.py