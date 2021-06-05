import sys
from collections import deque
si = sys.stdin.readline
n, m = list(map(int, si().split()))
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    x, y = list(map(int, si().split()))
    adj[x].append(y)
    adj[y].append(x)

visit = [False] * (n + 1)
def dfs(x):
    visit[x] = True
    for y in adj[x]:
        if visit[y]:
            continue
        dfs(y)

ans = 0
for i in range(1, n + 1):
    if visit[i]: continue
    ans += 1
    dfs(i)

print(ans)