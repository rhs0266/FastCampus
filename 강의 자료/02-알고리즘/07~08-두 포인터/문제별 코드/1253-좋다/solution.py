import sys
si = sys.stdin.readline
n = int(si())
a = list(map(int, si().split()))
a.sort()

def func(target_idx):
    L, R = 0, n - 1
    target = a[target_idx]
    while L < R:
        if L == target_idx: L += 1
        elif R == target_idx: R -= 1
        else:
            if a[L] + a[R] > target: R -= 1
            elif a[L] + a[R] < target: L += 1
            else: return True
    return False;

print(len([x for x in range(n) if func(x)]))