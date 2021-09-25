import sys
sys.setrecursionlimit(100005)
si = sys.stdin.readline

n, R, Q = map(int, si().split())
con = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    x, y = map(int, si().split())
    con[x].append(y)
    con[y].append(x)

Dy = [0] * (n + 1)
# Dy[x] 를 계산하는 함수
def DFS(x, prev):
    global Dy
    Dy[x] = 1
    for y in con[x]:
        if y == prev: continue
        DFS(y, x)
        Dy[x] += Dy[y]

DFS(R, -1)

for _ in range(Q):
    print(Dy[int(si())])
