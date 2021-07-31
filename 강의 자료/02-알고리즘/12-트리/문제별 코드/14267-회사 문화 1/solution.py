import sys
from collections import deque
si = sys.stdin.readline
n, m = map(int, si().split())
Dy = [0] * (n + 1)
children = [[] for _ in range(n + 1)]
sys.setrecursionlimit(100005)

par = list(map(int, si().split()))
for i in range(2, n + 1):
    children[par[i - 1]].append(i)

for _ in range(m):
    x, v = map(int, si().split())
    Dy[x] += v

# 내가 받은 칭찬을 부하 직원들에게 누적시켜주는 작업을 해주면 된다.
def dfs(x):
    for y in children[x]:
        Dy[y] += Dy[x]
        dfs(y)

dfs(1)
for i in range(1, n + 1):
    print(Dy[i], end=' ')
