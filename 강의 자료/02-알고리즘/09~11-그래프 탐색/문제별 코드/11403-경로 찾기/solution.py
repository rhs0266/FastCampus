import sys
from collections import deque
si = sys.stdin.readline
n = int(si())
adj = [list(map(int, si().split())) for _ in range(n)]

def bfs(x):
    visit = [0] * (n)
    queue = deque()
    queue.append(x)
    while queue:
        x = queue.popleft()
        for y in range(n):
            if not adj[x][y] or visit[y]:
                continue
            visit[y] = 1
            queue.append(y)
    for i in range(n):
        print(visit[i], end=' ')
    print()

for i in range(n):
    bfs(i)