def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    # YOUR CODE HERE
    return ['.']


def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()
