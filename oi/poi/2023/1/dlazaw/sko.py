from skolib import daj_n, pytanie, odpowiedz

n = daj_n()
pytanie(1, 1)
pytanie(123 % n + 1, 321 % n + 1)
odpowiedz(456 % n + 1, 654 % n + 1)