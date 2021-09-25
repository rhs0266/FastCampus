import sys
si = sys.stdin.readline

n = int(si())
a= [0] * n
for i in range(n):
    a[i] = int(si())

dy = [[0, 0] for _ in range(n + 2)]

# 초기값 채우기
dy[0][0], dy[0][1] = 0, a[0]

if n >= 2:
    dy[1][0], dy[1][1] = a[1], a[0] + a[1]

# 점화식을 토대로 dy 배열 채우기
for i in range(2, n):
    dy[i][0] = max(dy[i - 2][0] + a[i], dy[i - 2][1] + a[i])
    dy[i][1] = dy[i - 1][0] + a[i]

print(max(dy[n - 1][0], dy[n - 1][1]))
