import sys
si = sys.stdin.readline
n, k = list(map(int, si().split()))
a = [int(si()) for _ in range(n)]

def determination(amount):
    if amount == 0:
        return False
    sum = 0
    for x in a:
        sum += x // amount
    return sum >= k

l, r, ans = 0, 1 << 31, 0
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)
