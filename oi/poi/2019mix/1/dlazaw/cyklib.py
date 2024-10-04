__n, __tab = None, None
__b = False
__ended = False
__counter = 0

def __single_shift():
    # pomocnicza funkcja, ktorej zawodnik nie powinien uzywac
    if __n <= 0:
        print("Blad! N powinno byc dodatnie, gdy odpalamy single_shift().")
        exit(1)
    tmp = __tab[0]
    for i in range(__n - 1):
        __tab[i] = __tab[i+1]
    __tab[__n-1] = tmp

def __init():
    # pomocnicza funkcja, ktorej zawodnik nie powinien uzywac
    if __ended:
        print("Nie mozesz juz zadawac zapytan! Zakoncz program po udzieleniu odpowiedzi.")
        exit(1)

    global __b
    if __b:
        return None
    __b = True

    global __n
    global __tab

    __n, x0 = [int(x) for x in (input().split())]
    __tab    = [int(x) for x in (input().split())]
    for i in range(x0):
        __single_shift()

def circular_shift(x : int) -> int:
    __init()
    global __counter
    __counter += 1
    if __counter > 100:
        print("Za duzo zapytan!")
        exit(1)

    if x < 0 or x > 1000 * 1000 * 1000:
        print("Bledna wartosc przesuniecia!")
        exit(1)

    for i in range(x):
        __single_shift()

    return __tab[0]

def give_answer(x : int) -> None:
    __init()
    __ended = True

    if __n == x:
        print("Hurra, poprawny wynik:", x)
    else:
        print("Zle! Wypisano:", x, "a oczekiwano:", __n)
