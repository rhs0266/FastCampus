import sys
from collections import deque
si = sys.stdin.readline

T = int(si())
for _ in range(T):
    K, n, m = map(int, si().split())
    con = [[] for _ in range(n + 1)]
    indeg = [0] * (n + 1)

    for _ in range(m):
        x, y = map(int, si().split())
        con[x].append(y)
        indeg[y] += 1

    # 제일 앞에 "정렬될 수 있는" 정점 찾기
    order = [0] * (n + 1)
    maxCnt = [0] * (n + 1)
    Q = deque()
    for i in range(1, n + 1):
        if indeg[i] == 0:
            Q.append(i)
            order[i] = maxCnt[i] = 1

    ans = 0
    while Q:
        x = Q.popleft()
        if maxCnt[x] >= 2:
            order[x] += 1
        ans = max(ans, order[x])
        for y in con[x]:
            indeg[y] -= 1
            if indeg[y] == 0:
                Q.append(y)
            if order[y] == order[x]: maxCnt[y] += 1
            elif order[y] < order[x]:
                order[y] = order[x]
                maxCnt[y] = 1
    print(K, ans)