import sys
from collections import deque
si = sys.stdin.readline
n = int(si())
m = int(si())

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
        if 1 <= dist[x] <= 2:
            ret += 1
        if dist[x] == 2:
            continue
        for y in adj[x]:
            if dist[y] != -1:
                continue
            dist[y] = dist[x] + 1
            queue.append(y)
    return ret

print(bfs(1))
