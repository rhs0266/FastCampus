import sys
si = sys.stdin.readline
n, K = list(map(int, si().split()))
a = list(map(int, si().split()))
R, sum, ans = -1, 0, -100 * n
for L in range(n - K + 1):
    while R + 1 <= L + K - 1:
        R += 1
        sum += a[R]
    
    ans = max(ans, sum)

    sum -= a[L]

print(ans)