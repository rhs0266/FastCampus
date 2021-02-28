import sys
from collections import deque
si = sys.stdin.readline
n, m = list(map(int, si().split()))
a = [si().strip() for _ in range(n)]

dist = [[0] * m for _ in range(n)]
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def bfs():
    queue = deque()
    queue.append(0)
    queue.append(0)
    dist[0][0] = 1

    while queue:
        x = queue.popleft()
        y = queue.popleft()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
            if dist[nx][ny] != 0: continue
            if a[nx][ny] == '0': continue
            dist[nx][ny] = dist[x][y] + 1
            queue.append(nx)
            queue.append(ny)

bfs()
print(dist[n - 1][m - 1])