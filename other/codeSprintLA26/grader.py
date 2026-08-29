#!/usr/bin/env python3
#
# Testing tool for the Sorcerer's Rift problem
#
# Usage:
#
#   python3 testing_tool.py [-f inputfile] [-n N] [-m M] [-q] <program>
#
# There are three different ways to ask for input:
#    1. No flags (uses default test case)
#    2. -f set (this overrides all other flags). Please provide a valid path to an input file.
#       The format of the input file should match your generator:
#       - One line containing N and M.
#       - N-1 lines of edges in Hyrule.
#       - M-1 lines of edges in Lorule.
#       - One final line containing the rift locations U and V.
#    3. -n, -m are set together. The tool will warn if constraints are violated. 
#       If they are not, it runs your program on a randomly-generated test case with N and M nodes.
#
# The -q flag leads to only outputting the number of queries used without the actual execution.
#
# You can compile and run your solution as follows.
#
# If you have a Java solution that you would run using "java MyClass":
#   python3 testing_tool.py java MyClass
#
# If you have a Python solution:
#   python3 testing_tool.py python3 solution.py
#
# If you have a C++ solution stored in "sol.cpp":
#   g++ sol.cpp -o sol
#   python3 testing_tool.py ./sol
#

import argparse
import subprocess
import sys
import traceback
import random
import collections

QUERY_LIMIT = 36

# ── Random test case generator ────────────────────────────────────────────────
random.seed(5)
def generate_random_tree(n, start=0, max_degree=4):
    if n <= 1:
        return []

    edges = []
    degree = [0] * n
    nodes = list(range(n))
    random.shuffle(nodes)

    available_nodes = [nodes[0]]

    for i in range(1, n):
        new_node = nodes[i]

        # pick a parent from already available nodes
        parent = random.choice(available_nodes)

        edges.append((parent + start + 1, new_node + start + 1))
        degree[parent] += 1
        degree[new_node] += 1

        # if parent reached max_degree, remove it from available_nodes
        if degree[parent] == max_degree:
            available_nodes.remove(parent)

        # new_node can also become a parent
        if degree[new_node] < max_degree:
            available_nodes.append(new_node)

    return edges


# ── Judge logic ───────────────────────────────────────────────────────────────

def build_tree(n, m, edgesA, edgesB, true_u, true_v):
    """Build the full tree and compute depth and parents for fast path extraction."""
    adj = collections.defaultdict(list)
    for a, b in edgesA + edgesB + [(true_u, true_v)]:
        adj[a].append(b)
        adj[b].append(a)

    parent = [0] * (n + m + 1)
    depth = [0] * (n + m + 1)
    
    # Iterative BFS to compute depth and parent (prevents recursion depth issues)
    q = collections.deque([1])
    visited = [False] * (n + m + 1)
    visited[1] = True
    
    while q:
        curr = q.popleft()
        for nxt in adj[curr]:
            if not visited[nxt]:
                visited[nxt] = True
                parent[nxt] = curr
                depth[nxt] = depth[curr] + 1
                q.append(nxt)
                
    return parent, depth

def get_path(u, v, parent, depth):
    """Returns the set of nodes on the path between u and v."""
    path = []
    curr_u, curr_v = u, v
    
    while depth[curr_u] > depth[curr_v]:
        path.append(curr_u)
        curr_u = parent[curr_u]
        
    while depth[curr_v] > depth[curr_u]:
        path.append(curr_v)
        curr_v = parent[curr_v]
        
    while curr_u != curr_v:
        path.append(curr_u)
        path.append(curr_v)
        curr_u = parent[curr_u]
        curr_v = parent[curr_v]
        
    path.append(curr_u)
    return set(path)


# ── I/O helpers ───────────────────────────────────────────────────────────────

def send(p, line, quiet):
    if not quiet:
        print(f'  judge → {line}', flush=True)
    try:
        p.stdin.write(f'{line}\n')
        p.stdin.flush()
    except BrokenPipeError:
        pass  # solution already exited; will surface on next recv()


def recv(p, quiet):
    line = p.stdout.readline().strip()
    if line == '':
        assert False, 'Program terminated early or produced empty output'
    if not quiet:
        print(f'  sol   → {line}', flush=True)
    return line


def fatal(p, reason):
    print(f'\nWRONG ANSWER: {reason}', flush=True)
    p.kill()


# ── Argument parsing ──────────────────────────────────────────────────────────

parser = argparse.ArgumentParser(description="Testing tool for the Sorcerer's Rift problem")
parser.add_argument('-f', dest='inputfile', metavar='inputfile', default=None)
parser.add_argument('-n', type=int, default=None)
parser.add_argument('-m', type=int, default=None)
parser.add_argument('-q', dest='quiet', action='store_true', help='Suppress per-query output')
parser.add_argument('program', nargs='+', help='Invocation of your solution')
args = parser.parse_args()

# ── Build test case ───────────────────────────────────────────────────────────

edgesA = []
edgesB = []
true_u = -1
true_v = -1

if args.inputfile:
    with open(args.inputfile) as f:
        lines = [l.strip() for l in f if l.strip()]
    n, m = map(int, lines[0].split())
    if not (1 <= n < 200000): print(f'Warning: N={n} outside [1, 200000)')
    if not (1 <= m < 200000): print(f'Warning: M={m} outside [1, 200000)')
    
    idx = 1
    for _ in range(n - 1):
        parts = lines[idx].split()
        edgesA.append((int(parts[0]), int(parts[1])))
        idx += 1
        
    for _ in range(m - 1):
        parts = lines[idx].split()
        edgesB.append((int(parts[0]), int(parts[1])))
        idx += 1
        
    parts = lines[idx].split()
    true_u, true_v = int(parts[0]), int(parts[1])

elif args.n is not None and args.m is not None:
    n, m = args.n, args.m
    if not (1 <= n < 200000): print(f'Warning: N={n} outside [1, 200000)')
    if not (1 <= m < 200000): print(f'Warning: M={m} outside [1, 200000)')
    
    edgesA = generate_random_tree(n, start=0)
    edgesB = generate_random_tree(m, start=n)
    true_u = random.randint(1, n)
    true_v = random.randint(n + 1, n + m)

else:
    # Default: sample test case
    n, m = 3, 3
    edgesA = [(1, 2), (2, 3)]
    edgesB = [(4, 5), (5, 6)]
    true_u, true_v = 2, 5

parent, depth = build_tree(n, m, edgesA, edgesB, true_u, true_v)

print(f'Test case: N={n}  M={m}  Rift: {true_u} <-> {true_v}')
if not args.quiet:
    if n + m <= 20:
        print('Hyrule Edges:', edgesA)
        print('Lorule Edges:', edgesB)
    else:
        print('(Trees are too large to print explicitly)')
print()

# ── Run the program ───────────────────────────────────────────────────────────

with subprocess.Popen(' '.join(args.program), shell=True,
                      stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                      universal_newlines=True) as p:
    try:
        # Send initial data
        send(p, f'{n} {m}', args.quiet)
        for u, v in edgesA:
            send(p, f'{u} {v}', args.quiet)
        for u, v in edgesB:
            send(p, f'{u} {v}', args.quiet)
            
        queries = 0

        while True:
            line = recv(p, args.quiet)

            if line.startswith('? '):
                parts = line.split()
                if len(parts) != 5:
                    fatal(p, f'bad query format: {line!r}')
                    break
                    
                try:
                    w, x, y, z = map(int, parts[1:])
                except ValueError:
                    fatal(p, f'expected integers in query: {line!r}')
                    break
                    
                if not (1 <= w <= n + m and 1 <= x <= n + m and 1 <= y <= n + m and 1 <= z <= n + m):
                    fatal(p, f'query parameters out of bounds: {line!r}')
                    break
                    
                if queries >= QUERY_LIMIT:
                    fatal(p, f'query limit ({QUERY_LIMIT}) exceeded')
                    break
                    
                queries += 1
                
                # Fetch paths and calculate intersection
                path1 = get_path(w, x, parent, depth)
                path2 = get_path(y, z, parent, depth)
                intersection_len = len(path1.intersection(path2))
                
                send(p, str(intersection_len), args.quiet)

            elif line.startswith('! '):
                parts = line.split()
                if len(parts) != 3:
                    fatal(p, f'bad answer format: {line!r}')
                    break
                    
                try:
                    ans_u, ans_v = map(int, parts[1:])
                except ValueError:
                    fatal(p, f'expected integer after !: {line!r}')
                    break
                    
                if ans_u == true_u and ans_v == true_v:
                    # Check for trailing output
                    trailing = p.stdout.readline().strip()
                    if trailing != '':
                        print(f'\nWRONG ANSWER: trailing output after cuts: {trailing!r}')
                    else:
                        print(f'\nACCEPTED  —  {queries} / {QUERY_LIMIT} queries used')
                else:
                    fatal(p, f'expected {true_u} {true_v}, but got {ans_u} {ans_v}')
                break

            else:
                fatal(p, f'unrecognized output: {line!r}')
                break

    except Exception:
        traceback.print_exc()
    finally:
        sys.stdout.flush()
        sys.stderr.flush()