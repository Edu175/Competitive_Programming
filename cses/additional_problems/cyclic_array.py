n, k = map(int, input().split())
a = list(map(int, input().split()))

K = 19
p = -1
sum_val = 0
F = [[0] * (2 * n + 5) for _ in range(K)]

for i in range(2 * n):
    while p < 2 * n and sum_val <= k:
        sum_val += a[p + 1]
        p += 1
    F[0][i] = p
    sum_val -= a[i]

F[0][2 * n] = 2 * n

for k in range(1, K):
    for i in range(2 * n + 1):
        F[k][i] = F[k - 1][F[k - 1][i]]

res = n

for i in range(n):
    resi, x = 1, i
    for k in range(K - 1, -1, -1):
        if F[k][x] < i + n:
            x = F[k][x]
            resi += 1 << k
    res = min(res, resi)

print(res)

