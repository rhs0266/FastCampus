import sys
from collections import deque
si = sys.stdin.readline

n, m = map(int, si().split())
con = [[] for _ in range(n + 1)]
indeg = [0] * (n + 1)

for _ in range(m):
    x, y = map(int, si().split())
    con[x].append(y)
    indeg[y] += 1

# 제일 앞에 "정렬될 수 있는" 정점 찾기
Q = deque()
for i in range(1, n + 1):
    if indeg[i] == 0:
        Q.append(i)

# 정렬될 수 있는 정점이 있다면?
# 1. 정렬 결과에 추가하기
# 2. 정점과 연결된 간선 제거하기
# 3. 새롭게 "정렬 될 수 있는" 정점 Queue에 추가하기
while Q:
    x = Q.popleft()
    print(x, end=' ')
    for y in con[x]:
        indeg[y] -= 1
        if indeg[y] == 0:
            Q.append(y)
