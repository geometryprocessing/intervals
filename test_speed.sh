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
if [ ! -d "graphs" ] 
then
    mkdir graphs
fi
if [ ! -d "graphs/time" ]
then 
    mkdir graphs/time
fi
python deal_time.py