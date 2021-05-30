import sys
si = sys.stdin.readline
n, k = map(int, si().split())
a = si().split()

R, ans, sum = -1, -1 ,0
for L in range(n):
    while R + 1 < n and sum < k:
        R += 1
        if a[R] == '1':
            sum += 1
    if sum == k:
        if ans == -1:
            ans = R - L + 1
        ans = min(ans, R - L + 1)
    if a[L] == '1':
        sum -= 1

print(ans)