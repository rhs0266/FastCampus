import sys
from collections import deque
si = sys.stdin.readline
TT = int(si())
for _TT in range(TT):
    n = int(si())
    sx, sy = list(map(int, si().split()))
    ex, ey = list(map(int, si().split()))

    dist = [[-1] * n for _ in range(n)]
    dir = [(1, 2), (2, 1), (-1, 2), (-2, 1), (1, -2), (2, -1), (-1, -2), (-2, -1)]

    q = deque()
    q.append((sx, sy))
    dist[sx][sy] = 0
    while q:
        x, y = q.popleft()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if dist[nx][ny] != -1:
                continue
            q.append((nx, ny))
            dist[nx][ny] = dist[x][y] + 1
    print(dist[ex][ey])
