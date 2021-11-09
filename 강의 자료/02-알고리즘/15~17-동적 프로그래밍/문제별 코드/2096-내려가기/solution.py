import sys
si = sys.stdin.readline

n = int(si())
a= [0] * 4
dy_min = [[10000000, 10000000, 10000000, 10000000] for _ in range(2)]
dy_max = [[0, 0, 0, 0] for _ in range(2)]

# 초기값 채우기
a = [0] + list(map(int, si().split()))
for j in range(1, 4):
    dy_min[1][j] = a[j]
    dy_max[1][j] = a[j]

# 점화식을 토대로 dy 배열 채우기
for i in range(2, n + 1):
    a = [0] + list(map(int, si().split()))
    for cur in range(1, 4):
        dy_min[i % 2][cur] = 10000000
        dy_max[i % 2][cur] = 0
        for prev in range(1, 4):
            if abs(cur - prev) > 1:
                continue
            dy_min[i % 2][cur] = min(dy_min[i % 2][cur], dy_min[(i + 1) % 2][prev] + a[cur])
            dy_max[i % 2][cur] = max(dy_max[i % 2][cur], dy_max[(i + 1) % 2][prev] + a[cur])

print(max(dy_max[n % 2][1:]), end=' ')
print(min(dy_min[n % 2][1:]))
