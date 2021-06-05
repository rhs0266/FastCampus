import sys
from collections import deque
si = sys.stdin.readline
n, m = map(int, si().split())
a = [list(map(int, si().split())) for _ in range(n)]
blank = [(i, j) for i in range(n) for j in range(m) if a[i][j] == 0]
ans = 0

def bfs():
    global ans
    cnt = 0
    visit = [[False] * m for _ in range(n)]
    dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

    Q = deque()
    for i in range(n):
        for j in range(m):
            if a[i][j] == 2:
                visit[i][j] = True
                Q.append(i)
                Q.append(j)

    while Q:
        x = Q.popleft()
        y = Q.popleft()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if a[nx][ny] != 0:
                continue
            if visit[nx][ny]:
                continue
            visit[nx][ny] = True
            Q.append(nx)
            Q.append(ny)

    for i in range(n):
        for j in range(m):
            if a[i][j] == 0 and not visit[i][j]:
                cnt += 1
    
    ans = max(ans, cnt)


def dfs(idx, selected_cnt):
    if selected_cnt == 3:
        bfs()
        return
    
    if idx == len(blank):
        return
    
    a[blank[idx][0]][blank[idx][1]] = 1
    dfs(idx + 1, selected_cnt + 1)

    a[blank[idx][0]][blank[idx][1]] = 0
    dfs(idx + 1, selected_cnt)

dfs(0, 0)
print(ans)