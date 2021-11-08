import sys
from collections import deque
si = sys.stdin.readline
n, m = list(map(int, si().split()))
a = [si().strip() for _ in range(n)]

visit = [[False] * m for _ in range(n)]
dist_hedgehog = [[-1] * m for _ in range(n)]
dist_water = [[-1] * m for _ in range(n)]
dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def bfs_water():
    q = deque()
    for i in range(n):
        for j in range(m):
            if a[i][j] == '*':
                q.append((i,j))
                visit[i][j] = True
                dist_water[i][j] = 0
    while q:
        x, y = q.popleft()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if a[nx][ny] != '.':
                continue
            if visit[nx][ny]:
                continue
            q.append((nx, ny))
            visit[nx][ny] = True
            dist_water[nx][ny] = dist_water[x][y] + 1

def bfs_hedgehog():
    q = deque()
    for i in range(n):
        for j in range(m):
            visit[i][j] = False
            if a[i][j] == 'S':
                q.append((i,j))
                visit[i][j] = True
                dist_hedgehog[i][j] = 0
    while q:
        x, y = q.popleft()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if a[nx][ny] != '.' and a[nx][ny] != 'D':
                continue
            if dist_water[nx][ny] != -1 and dist_water[nx][ny] <= dist_hedgehog[x][y] + 1:
                continue
            if visit[nx][ny]:
                continue
            q.append((nx, ny))
            visit[nx][ny] = True
            dist_hedgehog[nx][ny] = dist_hedgehog[x][y] + 1

bfs_water()
bfs_hedgehog()
for i in range(n):
    for j in range(m):
        if a[i][j] == 'D':
            if dist_hedgehog[i][j] == -1:
                print("KAKTUS")
            else:
                print(dist_hedgehog[i][j])