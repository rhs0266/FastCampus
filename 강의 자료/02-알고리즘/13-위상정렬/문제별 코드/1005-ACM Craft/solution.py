import sys
from collections import deque
si = sys.stdin.readline

Q = int(si())
for _ in range(Q):
    n, m = map(int, si().split())
    T = [0] + list(map(int, si().split()))
    T_done = [0] * (n + 1)
    con = [[] for _ in range(n + 1)]
    indeg = [0] * (n + 1)

    for _ in range(m):
        x, y = map(int, si().split())
        con[x].append(y)
        # indegree 계산하기
        indeg[y] += 1

    # 제일 앞에 "정렬될 수 있는" 정점 찾기
    Q = deque()
    for i in range(1, n + 1):
        if indeg[i] == 0:
            Q.append(i)
            T_done[i] = T[i]

    # 위상 정렬 순서대로 T_done 계산을 함께 해주기
    while Q:
        x = Q.popleft()
        for y in con[x]:
            indeg[y] -= 1
            if indeg[y] == 0:
                Q.append(y)
            T_done[y] = max(T_done[y], T_done[x] + T[y])
    
    W = int(si())
    print(T_done[W])
