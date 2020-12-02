import sys

n = int(sys.stdin.readline())
a = []

for i in range(n):
    a.append(sys.stdin.readline().strip())

a.sort(key = lambda x: (len(x), x))

for i in range(n):
    if i == 0 or a[i] != a[i-1]:
        print(a[i])