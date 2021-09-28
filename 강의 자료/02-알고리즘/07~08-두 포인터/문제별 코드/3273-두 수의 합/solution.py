import sys
si = sys.stdin.readline
n = int(si())
a = list(map(int, si().split()))
S = int(si())
a.sort()
L, R, ans = 0, n - 1, 0
while L < R:
    if a[L] + a[R] == S:
        ans += 1
    if a[L] + a[R] >= S:
        R -= 1
    else:
        L += 1
print(ans)