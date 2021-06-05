import sys
from collections import deque
si = sys.stdin.readline
n = int(si())
adj = [[] for _ in range(n + 1)]
parent = [0] * (n + 1)

for _ in range(n - 1):
    x, y = list(map(int, si().split()))
    adj[x].append(y)
    adj[y].append(x)

visit = [0] * (n + 1)
def bfs(x):
    queue = deque()
    queue.append(x)
    visit[x] = 1
    while queue:
        x = queue.popleft()
        for y in adj[x]:
            if visit[y]:
                continue
            visit[y] = 1
            parent[y] = x
            queue.append(y)

bfs(1)
for i in range(2, n + 1):
    print(parent[i])
    