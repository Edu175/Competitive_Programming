#include "skolib.h"
#include <iostream>
#include <vector>

int _n;
std::vector<std::vector<int>> _board;

void _init() {
    std::cin >> _n;
    _board.resize(_n, std::vector<int>(_n));
    for (int y = 0; y < _n; y++)
        for (int x = 0; x < _n; x++)
            std::cin >> _board[x][y];
}

int daj_n() {
    if (_n == 0) _init();
    return _n;
}

int pytanie(int x, int y) {
    if (_n == 0) _init();
    return _board[x-1][y-1];
}

void odpowiedz(int xs, int ys) {
    if (_n == 0) _init();
    if (_board[xs-1][ys-1] == 0)
        std::cout << "OK\n" << "x = " << xs << ", y = " << ys << std::endl;
    else
        std::cout << "BLAD\n" << std::endl;
    exit(0);
}
