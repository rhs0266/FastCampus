import sys
from collections import deque
si = sys.stdin.readline
n, m, V = list(map(int, si().split()))
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    x, y = list(map(int, si().split()))
    adj[x].append(y)
    adj[y].append(x)

for i in range(1, n + 1):
    adj[i].sort()

visit = [0] * (n + 1)
def dfs(x):
    visit[x] = 1
    print(x, end=' ')
    for y in adj[x]:
        if visit[y]:
            continue
        dfs(y)

def bfs(x):
    visit = [0] * (n + 1)
    queue = deque()
    queue.append(x)
    visit[x] = 1
    while queue:
        x = queue.popleft()
        print(x, end=' ')
        for y in adj[x]:
            if visit[y]:
                continue
            visit[y] = 1
            queue.append(y)

dfs(V)
print()
bfs(V)