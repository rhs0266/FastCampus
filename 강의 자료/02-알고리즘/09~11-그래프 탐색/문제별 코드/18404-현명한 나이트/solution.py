import sys
from collections import deque
si = sys.stdin.readline
n, m = list(map(int, si().split()))
sx, sy = list(map(int, si().split()))

dist = [[-1] * (n + 1) for _ in range(n + 1)]
dir = [(1, 2), (2, 1), (-1, 2), (-2, 1), (1, -2), (2, -1), (-1, -2), (-2, -1)]

q = deque()
q.append((sx, sy))
dist[sx][sy] = 0
while q:
    x, y = q.popleft()
    for dx, dy in dir:
        nx, ny = x + dx, y + dy
        if nx < 1 or ny < 1 or nx > n or ny > n:
            continue
        if dist[nx][ny] != -1:
            continue
        q.append((nx, ny))
        dist[nx][ny] = dist[x][y] + 1

for _ in range(m):
    ex, ey = list(map(int, si().split()))
    print(dist[ex][ey], end=' ')
