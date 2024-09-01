# compilation
# g++ tests/test.cpp src/matrix.cpp src/series.cpp -o build/test

# run program with memory verification

g++ tests/test.cpp -o build/test

cd build
./test
cd ..