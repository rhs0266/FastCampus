import sys
from collections import deque
si = sys.stdin.readline

n, m = map(int, si().split())
con = [[] for _ in range(n + 1)]
indeg = [0] * (n + 1)

# A1, A2, ... Acnt 순서로 나가야 한다면,
# A1 -> A2
# A2 -> A3
#  ...
# A(cnt-1) -> Acnt
# 의 간선을 만들어주면 된다.

for _ in range(m):
    order = list(map(int, si().split()))
    for i in range(2, len(order)):
        con[order[i - 1]].append(order[i])
        indeg[order[i]] += 1


# 우선순위에 대한 조건을 간선으로 표현했으므로 위상정렬을 수행하면 된다.
Q = deque()
for i in range(1, n + 1):
    if indeg[i] == 0:
        Q.append(i)

ans = []
while Q:
    x = Q.popleft()
    ans.append(x)
    for y in con[x]:
        indeg[y] -= 1
        if indeg[y] == 0:
            Q.append(y)

if len(ans) != n:
    print(0)
else:
    for x in ans: print(x)
