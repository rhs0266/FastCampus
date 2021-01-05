import sys
si = sys.stdin.readline
n, S = list(map(int, si().split()))
a = list(map(int, si().split()))
R, sum, ans = -1, 0, 0
for L in range(n):
    while R + 1 < n and sum < S:
        R += 1
        sum += a[R]
    
    if sum == S:
        ans += 1

    sum -= a[L]

print(ans)