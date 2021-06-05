import sys
from collections import deque
si = sys.stdin.readline
n, m = map(int, si().split())
a = [si().strip() for _ in range(n)]
sys.setrecursionlimit(100000)

visit = [[False] * m for _ in range(n)]
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
totalSheep, totalWolf, sheep, wolf = 0, 0, 0, 0

def dfs(x, y):
    global sheep, wolf
    if a[x][y] == 'o':
        sheep += 1
    if a[x][y] == 'v':
        wolf += 1
    visit[x][y] = True
    for dx, dy in dir:
        nx, ny = x + dx, y + dy
        if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
        if visit[nx][ny]: continue
        if a[nx][ny] == '#': continue
        dfs(nx, ny)

for i in range(n):
    for j in range(m):
        if a[i][j] != '#' and not visit[i][j]:
            sheep, wolf = 0, 0
            dfs(i, j)
            if sheep > wolf: totalSheep += sheep
            else: totalWolf += wolf
print(totalSheep, totalWolf)