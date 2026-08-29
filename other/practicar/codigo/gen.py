import sys

def generate_true_worst_case():
    n = 100000
    
    comps = []
    sz = 1
    current_sum = 0
    
    # Greedily add 4 of each size to maximize the items/sqrt(c) ratio
    while current_sum + sz * 4 <= n:
        comps.extend([sz, sz, sz, sz])
        current_sum += sz * 4
        sz += 1
        
    # Throw any remaining budget into a single component to ensure sum == n
    rem = n - current_sum
    if rem > 0:
        comps.append(rem)
        
    edges = []
    node_id = 1
    
    # Build a simple path for each component
    for s in comps:
        for i in range(1, s):
            edges.append((node_id + i - 1, node_id + i))
        node_id += s
        
    m = len(edges)
    
    # Output to stdout
    print(f"{n} {m}")
    for u, v in edges:
        print(f"{u} {v}")
        
    # Print stats to stderr so it doesn't corrupt the .in file
    print(f"[DEBUG] Nodes (n): {n}", file=sys.stderr)
    print(f"[DEBUG] Edges (m): {m}", file=sys.stderr)
    print(f"[DEBUG] Number of components: {len(comps)}", file=sys.stderr)
    print(f"[DEBUG] Distinct sizes: {sz - 1}", file=sys.stderr)
    print(f"[DEBUG] Knapsack items generated: {(sz - 1) * 3 + (1 if rem > 0 else 0)}", file=sys.stderr)

if __name__ == '__main__':
    generate_true_worst_case()