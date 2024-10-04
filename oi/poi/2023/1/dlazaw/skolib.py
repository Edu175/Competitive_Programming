import sys

_n = int(input())
_board = [list(map(int, input().split())) for _ in range(_n)]

def daj_n():
    return _n

def pytanie(x, y):
    return _board[y-1][x-1]

def odpowiedz(xs, ys):
    if _board[ys-1][xs-1] == 0:
        print("OK")
    else:
        print("BLAD")
    sys.exit(0)
