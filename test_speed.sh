# do the speed test and print out the table
if [ ! -d "build" ] 
then
    mkdir build
fi
cd build
rm time.txt
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
./tests/speed_bin >> time.txt
cd ..
python deal_time.py