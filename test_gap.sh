# do the gap test and plot the distribution of gap size vs the base (default filib c version)
rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
./tests/gap_bin >> gaps.txt
cd ..
mkdir datas
rm -rf graphs
mkdir graphs
python plot_gap_distribution.py