import sys
si = sys.stdin.readline
n, M = list(map(int, si().split()))
a = sorted([int(si()) for _ in range(n)])
R, ans = 0, 1 << 31
for L in range(n):
    while R + 1 < n and a[R] - a[L] < M:
        R += 1
    
    if a[R] - a[L] >= M:
        ans = min(ans, a[R] - a[L])

print(ans)