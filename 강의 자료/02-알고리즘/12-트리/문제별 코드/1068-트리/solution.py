import sys
from collections import deque
si = sys.stdin.readline
n = int(si())
parent = list(map(int, si().split()))
child = [[] for _ in range(n)]
leaf = [0] * n
erased = int(si())
root = 0
for i in range(n):
    if parent[i] == -1:
        root = i
    else:
        if erased == i:
            continue
        child[parent[i]].append(i)

def dfs(x, par):
    if not child[x]:
        leaf[x] = 1
    for y in child[x]:
        if y == par:
            continue
        dfs(y, x)
        leaf[x] += leaf[y]

if root != erased:
    dfs(root, -1)
print(leaf[root])