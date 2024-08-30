# compilation
g++ tests/test.cpp src/matrix.cpp src/series.cpp -o build/test

valgrind --log-file="memory_report.txt" build/test
# basic memory report
echo
echo "Basic Memory Check:"
echo "==============================================="
echo
cat memory_report.txt