import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

def determination(candidate):
    sum = 0
    for i in range(1, n + 1):
        sum += min(n, candidate // i)
    return sum >= k

l, r, ans = 1, n * n, 0
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        r = mid - 1
    else:
        l = mid + 1

print(ans)