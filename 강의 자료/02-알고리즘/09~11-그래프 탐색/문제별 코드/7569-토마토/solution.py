import sys
from collections import deque
si = sys.stdin.readline
M, N = list(map(int, si().split()))
a = []
for n in range(N):
    a.append(list(map(int, si().split())))
            
dist = [[-1 for m in range(M)] for n in range(N)]

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]

q = deque()
for n in range(N):
    for m in range(M):
        if a[n][m] == 1:
            dist[n][m] = 0
            q.append((n, m))

while q:
    n, m = q.popleft()
    for dn, dm in dir:
        nn, nm = n + dn, m + dm
        if nn < 0 or nm < 0 or nn >= N or nm >= M:
            continue
        if dist[nn][nm] != -1:
            continue
        if a[nn][nm] == -1:
            continue
        q.append((nn, nm))
        dist[nn][nm] = dist[n][m] + 1

ans = 0

for n in range(N):
    for m in range(M):
        if a[n][m] == -1: continue
        if dist[n][m] == -1: ans = -1
        if ans == -1: continue
        ans = max(ans, dist[n][m])

print(ans)
