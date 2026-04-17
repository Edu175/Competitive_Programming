def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    return [(0, 0) for _ in range(K)]


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        result = solve(N, M, K, GRID)
        for r, c in result:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()
