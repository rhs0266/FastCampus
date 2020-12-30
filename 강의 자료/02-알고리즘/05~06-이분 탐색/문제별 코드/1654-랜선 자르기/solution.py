import sys
si = sys.stdin.readline
k, n = list(map(int, si().split()))
a = []
for i in range(k):
    a.append(int(si()))

def determination(len):
    sum = 0
    for x in a:
        sum += x // len
    return sum >= n

l, r, ans = 1, 1 << 31, 0
while l <= r:
    mid = (l + r) // 2
    if determination(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)