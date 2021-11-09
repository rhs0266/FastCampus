import sys
sys.setrecursionlimit(10005)
si = sys.stdin.readline

n = int(si())
a = [0] + list(map(int, si().split()))
con = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    x, y = list(map(int, si().split()))
    con[x].append(y)
    con[y].append(x)

dy = [[0, 0] for _ in range(n + 1)]
def dfs(x, par):
    dy[x][1] = a[x]
    for y in con[x]:
        if y == par: continue
        dfs(y, x)
        dy[x][0] += max(dy[y])
        dy[x][1] += dy[y][0]

dfs(1, -1)
print(max(dy[1]))