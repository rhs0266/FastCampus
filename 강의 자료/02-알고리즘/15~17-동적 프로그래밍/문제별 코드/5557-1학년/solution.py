import sys
si = sys.stdin.readline

n = int(si())
a = list(map(int, si().split()))
dy = [[0] * 21 for _ in range(n)]

# 초기값 구하기
dy[0][a[0]] = 1

# 점화식을 토대로 dy 배열 채우기
for i in range(1, n - 1):
    for prev in range(21):
        for cur in [prev - a[i], prev + a[i]]:
            if cur < 0 or cur > 20: continue
            dy[i][cur] += dy[i - 1][prev]

print(dy[n - 2][a[n - 1]])
