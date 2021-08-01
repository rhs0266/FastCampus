import sys
from collections import deque
si = sys.stdin.readline

n, m, K = map(int, si().split())
cnt = [0] * (n + 1)
con = [[] for _ in range(n + 1)]
indeg = [0] * (n + 1)
satisfaction = [0] * (n + 1)

for _ in range(m):
    x, y = map(int, si().split())
    con[x].append(y)
    indeg[y] += 1

abnormal = False
for _ in range(K):
    t, x = map(int, si().split())
    if t == 1:
        if satisfaction[x] < indeg[x]:
            abnormal = True
        cnt[x] += 1
        if cnt[x] == 1:
            for y in con[x]:
                satisfaction[y] += 1
    else:
        if cnt[x] == 0:
            abnormal = True
        cnt[x] -= 1
        if cnt[x] == 0:
            for y in con[x]:
                satisfaction[y] -= 1

print("King-God-Emperor" if not abnormal else "Lier!")
