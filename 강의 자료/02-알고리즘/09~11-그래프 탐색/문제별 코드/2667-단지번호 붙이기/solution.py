import sys
from collections import deque
si = sys.stdin.readline
n = int(si())
a = [si().strip() for _ in range(n)]

visit = [[False] * n for _ in range(n)]
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def dfs(x, y):
    global group_cnt
    group_cnt += 1
    visit[x][y] = True
    for dx, dy in dir:
        nx, ny = x + dx, y + dy
        if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
        if visit[nx][ny]: continue
        if a[nx][ny] == '0': continue
        dfs(nx, ny)

groups = []
group_cnt = 0
for i in range(n):
    for j in range(n):
        if a[i][j] == '0' or visit[i][j]:
            continue
        group_cnt = 0
        dfs(i, j)
        groups.append(group_cnt)

groups.sort()
print(len(groups))
for g in groups:
    print(g)