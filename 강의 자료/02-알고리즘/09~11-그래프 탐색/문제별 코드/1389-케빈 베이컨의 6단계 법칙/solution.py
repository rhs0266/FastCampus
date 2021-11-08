import sys
from collections import deque
si = sys.stdin.readline
n, m = list(map(int, si().split()))

adj = [[] for _ in range(n + 1)]

for _ in range(m):
    x, y = list(map(int, si().split()))
    adj[x].append(y)
    adj[y].append(x)

def bfs(x):
    dist = [-1] * (n + 1)
    ret = 0
    queue = deque()
    queue.append(x)
    dist[x] = 0
    while queue:
        x = queue.popleft()
        ret += dist[x]
        for y in adj[x]:
            if dist[y] != -1:
                continue
            dist[y] = dist[x] + 1
            queue.append(y)
    return ret

minV, minIdx = bfs(1), 1
for i in range(2, n + 1):
    v = bfs(i)
    if minV > v:
        minV, minIdx = v, i

print(minIdx)
