from itertools import product

MOD = 10**9 + 7

n = int(input())
parents = list(map(int, input().split())) if n > 1 else []
R, G = map(int, input().split())

# Build children for each node
children = [[] for _ in range(n)]
for i in range(1, n):
    p = parents[i-1]
    children[p].append(i)

# Identify leaves (nodes with no children)
leaves = [i for i in range(n) if not children[i]]

# Precompute the path from each node to the root
paths = []
for i in range(n):
    path = []
    current = i
    while True:
        path.append(current)
        if current == 0:
            break
        current = parents[current-1]
    paths.append(path)

# Generate all possible (r, g) options for each node
node_options = []
for _ in range(n):
    options = [(r, g) for r in range(R + 1) for g in range(G + 1)]
    node_options.append(options)

count = 0

# Iterate over all possible assignments
for assignment in product(*node_options):
    r = [0] * n
    g = [0] * n
    valid = True

    for i in range(n):
        r[i], g[i] = assignment[i]

    # Check condition a: no green in path if node has red
    for i in range(n):
        if r[i] > 0:
            for j in paths[i]:
                if g[j] != 0:
                    valid = False
                    break
            if not valid:
                break
    if not valid:
        continue

    # Check condition b: sum R and G for each leaf's path
    for leaf in leaves:
        leaf_path = paths[leaf]
        sum_r = sum(r[j] for j in leaf_path)
        sum_g = sum(g[j] for j in leaf_path)
        if sum_r != R or sum_g != G:
            valid = False
            break
    if valid:
        count += 1

print(count % MOD)