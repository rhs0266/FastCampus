import sys
si = sys.stdin.readline
n = int(si())
a = sorted(list(map(int, si().split())))

L, R = 0, n - 1
v1, v2, best_sum = 0, 0, 1 << 31
while L < R:
    if best_sum > abs(a[L] + a[R]):
        best_sum = abs(a[L] + a[R])
        v1, v2 = a[L], a[R]
    if a[L] + a[R] > 0: R -= 1
    else: L += 1

print(v1, v2)