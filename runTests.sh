# COMPILE AND RUN SERIES TESTS
g++ tests/teste_series.cpp src/series.cpp -o build/tests/series/test_series

cd build/tests/series
./test_series
cd ../..

# COMPILE AND RUN MATRIX TESTS