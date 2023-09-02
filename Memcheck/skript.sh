g++ -g -O0 -Wall main.cpp solver.cpp
valgrind --show-leak-kinds=all --leak-check=full --log-file="memchech.txt" ./a.out <primer.txt
