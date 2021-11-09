import sys
si = sys.stdin.readline

Dy = [[0 for _ in range(10)] for _ in range(65)]

for num in range(10):
    Dy[1][num] = 1

for len in range(2, 65):
    for num in range(10):
        for prev in range(num + 1):
            Dy[len][num] += Dy[len - 1][prev]

Q = int(si())
for _ in range(Q):
    n = int(si())
    print(sum(Dy[n]))
