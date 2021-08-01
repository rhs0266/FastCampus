import sys
from collections import deque
si = sys.stdin.readline

n = int(si())
m = int(si())
con = [[] for _ in range(n + 1)]
indeg = [0] * (n + 1)
cnt = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    y, x, v = map(int, si().split())
    con[x].append((y, v))
    indeg[y] += 1

# 기본 부품 찾기
Q = deque()
for i in range(1, n + 1):
    if indeg[i] == 0:
        Q.append(i)
        cnt[i][i] = 1

# 먼저 만들 수 있는 제품들부터 차례대로 만들어서 필요 기본 부품 개수 계산하기
while Q:
    x = Q.popleft()
    for y, v in con[x]:
        indeg[y] -= 1
        # 제품 y에 제품 x 가 v 개 필요하므로 기본 부품 개수에 v 를 곱해서 누적시켜 준다.
        for i in range(1, n + 1):
            cnt[y][i] += cnt[x][i] * v
        if indeg[y] == 0:
            Q.append(y)

for i in range(n + 1):
    if cnt[n][i] != 0:
        print(i, cnt[n][i])
