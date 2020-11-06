# do the gap test and plot the distribution of gap size vs the base (default filib c version)
if [ ! -d "build" ] 
then
    mkdir build
fi
cd build
rm gaps.txt
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
./tests/gap_bin >> gaps.txt
cd ..
if [ ! -d "datas"]
then
    mkdir datas
fi
if [ ! -d "graphs"]
then
    mkdir graphs
fi
python plot_gap_distribution.py