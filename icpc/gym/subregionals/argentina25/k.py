import sys
from collections import deque

sys.setrecursionlimit(300000)

B = 150
MAXN = 10**5 + 5
K = 18

n = 0
cnt = 0
col = [0] * MAXN
D = [0] * MAXN
P = [0] * MAXN
S = [0] * MAXN
nod = [[] for _ in range(MAXN)]
g = [[] for _ in range(MAXN)]
ord = []
big = [0] * MAXN
dis = [[] for _ in range(MAXN)]
t = [[] for _ in range(MAXN)]

# --- dfs1 ---
def dfs1(x, fa):
    global cnt
    P[x] = len(ord)
    ord.append(x)
    nod[col[x]].append(x)
    S[x] = cnt
    cnt += 1
    for y in g[x]:
        if y != fa:
            D[y] = D[x] + 1
            dfs1(y, x)
            ord.append(x)

# --- BFS for multiple sources ---
def bfs(sources):
    dist = [-1] * n
    q = deque()
    for x in sources:
        dist[x] = 0
        q.append(x)
    while q:
        y = q.popleft()
        for k in g[y]:
            if dist[k] == -1:
                dist[k] = dist[y] + 1
                q.append(k)
    return dist

def dobig(c):
    big[c] = 1
    d = bfs(nod[c])
    dis[c] = [n + 5] * n
    for i in range(n):
        dis[c][col[i]] = min(dis[c][col[i]], d[i])

# --- LCA via RMQ ---
def oper(i, j):
    return i if D[i] < D[j] else j

st = [[0] * (1 << K) for _ in range(K)]

def st_init(a):
    m = len(a)
    for i in range(m):
        st[0][i] = a[i]
    k = 1
    while (1 << k) <= m:
        for i in range(m - (1 << k) + 1):
            st[k][i] = oper(st[k-1][i], st[k-1][i + (1 << (k-1))])
        k += 1

def st_query(s, e):
    k = (e - s).bit_length() - 1
    return oper(st[k][s], st[k][e - (1 << k)])

def lca(x, y):
    l, r = P[x], P[y]
    if l > r:
        l, r = r, l
    p = st_query(l, r + 1)
    return p

# --- dfs2 on virtual tree ---
ca = cb = res = 0

def dfs2(x):
    global res
    d = [2*n+5, 2*n+5]
    if col[x] == ca: d[0] = D[x]
    if col[x] == cb: d[1] = D[x]
    for y in t[x]:
        cur = dfs2(y)
        d[0] = min(d[0], cur[0])
        d[1] = min(d[1], cur[1])
    res = min(res, d[0] + d[1] - 2*D[x])
    return d

def merge(a, b):
    u, v = nod[a], nod[b]
    ret = []
    l = r = 0
    while l < len(u) or r < len(v):
        if l == len(u) or (r < len(v) and S[v[r]] < S[u[l]]):
            ret.append(v[r]); r += 1
        else:
            ret.append(u[l]); l += 1
    return ret

def add_edge(x, y):
    if y != -1:
        t[x].append(y)

def query(x, y):
    global ca, cb, res
    a, b = col[x], col[y]
    if a == b:
        return 0
    if big[b]:
        a, b = b, a
    if big[a]:
        return dis[a][b]
    v = merge(a, b)
    s = [v[0]]
    ult = -1

    virt = []
    for i in range(1, len(v)):
        x = v[i]
        p = lca(s[-1], x)
        virt.append(p)

        while s and lca(s[-1], p) != s[-1]:
            add_edge(s[-1], ult)
            ult = s[-1]
            s.pop()

        if not s or p != s[-1]:
            s.append(p)
        add_edge(p, ult)
        ult = -1
        if p != x:
            s.append(x)

    while s:
        add_edge(s[-1], ult)
        ult = s[-1]
        s.pop()

    rt = ult
    ca, cb = a, b
    res = n + 5
    dfs2(rt)

    for lst in [v, virt]:
        for i in lst:
            t[i].clear()

    return res

# --- main ---
def main():
    global n
    input = sys.stdin.readline
    n = int(input())
    cols = list(map(int, input().split()))
    for i in range(n):
        col[i] = cols[i] - 1
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)
    dfs1(0, -1)
    for c in range(n):
        if len(nod[c]) >= B:
            dobig(c)
    st_init(ord)
    q = int(input())
    for _ in range(q):
        x, y = map(int, input().split())
        print(query(x - 1, y - 1))

if __name__ == "__main__":
    main()