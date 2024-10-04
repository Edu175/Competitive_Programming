from cyklib import circular_shift, give_answer

if __name__ == "__main__":
    t = [circular_shift(i) % 1234 for i in range(100)]
    give_answer(sum(t))
