# compilation
g++ tests/teste_series.cpp src/matrix.cpp src/series.cpp -o build/tests_memcheck

valgrind --log-file="memory_report.txt" build/tests_memcheck
# basic memory report
echo
echo "Basic Memory Check:"
echo "==============================================="
echo
cat memory_report.txt