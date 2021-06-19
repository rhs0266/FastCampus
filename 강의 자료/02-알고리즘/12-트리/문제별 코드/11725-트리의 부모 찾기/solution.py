import sys
from collections import deque
si = sys.stdin.readline
n = int(si())
adj = [[] for _ in range(n + 1)]
parent = [0] * (n + 1)
sys.setrecursionlimit(100005)

for _ in range(n - 1):
    x, y = list(map(int, si().split()))
    adj[x].append(y)
    adj[y].append(x)

def dfs(x, par):
    for y in adj[x]:
        if y == par:
            continue
        parent[y] = x
        dfs(y, x)

dfs(1, -1)
for i in range(2, n + 1):
    print(parent[i])
