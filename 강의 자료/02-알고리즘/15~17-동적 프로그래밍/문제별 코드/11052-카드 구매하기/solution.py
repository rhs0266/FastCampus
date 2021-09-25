import sys
si = sys.stdin.readline

n = int(si())
a = [0] + list(map(int, si().split()))
dy = [0] * (n + 1)

# 초기값 구하기
pass

# 점화식을 토대로 dy 배열 채우기
for i in range(1, n + 1):
    for cnt in range(1, i + 1):
        dy[i] = max(dy[i], dy[i - cnt] + a[cnt])

print(dy[n])
