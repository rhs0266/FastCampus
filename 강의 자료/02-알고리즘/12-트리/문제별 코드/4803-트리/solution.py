import sys
from collections import deque
si = sys.stdin.readline
def solve(tt):
    n, m = map(int, si().split())
    if n == 0 and m == 0:
        return False
    adj = [[] for _ in range(n + 1)]
    visit = [0] * (n + 1)
    sys.setrecursionlimit(100005)

    for _ in range(m):
        x, y = list(map(int, si().split()))
        adj[x].append(y)
        adj[y].append(x)

    vertex_cnt = 0
    edge_cnt = 0
    def dfs(x):
        nonlocal vertex_cnt, edge_cnt
        visit[x] = True
        vertex_cnt += 1
        edge_cnt += len(adj[x])
        for y in adj[x]:
            if visit[y]:
                continue
            dfs(y)

    ans = 0
    for i in range(1, n + 1):
        if visit[i]: continue
        vertex_cnt, edge_cnt = 0, 0
        dfs(i)
        if edge_cnt == (vertex_cnt - 1) * 2:
            ans += 1
    print(f'Case {tt}: ', end='')
    if ans == 0:
        print("No trees.")
    elif ans == 1:
        print("There is one tree.")
    else:
        print(f"A forest of {ans} trees.")
    return True

tt = 0
while True:
    tt = tt + 1
    if not solve(tt):
        break
