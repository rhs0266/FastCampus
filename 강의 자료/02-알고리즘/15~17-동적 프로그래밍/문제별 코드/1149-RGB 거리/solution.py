import sys
si = sys.stdin.readline

n = int(si())
dy = [[0] * 3 for _ in range(n + 1)]

# 초기값 구하기
pass

# dy[i][j] := 1 ~ i번 집까지 칠했고, i번 집을 j번 색으로 색칠하는 경우 중 최소 비용
# 점화식을 토대로 dy 배열 채우기
for i in range(1, n + 1):
    a = list(map(int, si().split()))
    dy[i][0] = min(dy[i - 1][1], dy[i - 1][2]) + a[0]
    dy[i][1] = min(dy[i - 1][0], dy[i - 1][2]) + a[1]
    dy[i][2] = min(dy[i - 1][0], dy[i - 1][1]) + a[2]

print(min(dy[n]))
