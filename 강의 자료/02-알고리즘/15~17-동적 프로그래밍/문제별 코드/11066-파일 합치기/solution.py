import sys
si = sys.stdin.readline

def solve():
    n = int(si())
    a = [0] + list(map(int, si().split()))

    sum = [[0] * (n + 1) for _ in range(n + 1)]
    dy = [[0] * (n + 1) for _ in range(n + 1)]

    # Preprocess
    for i in range(n + 1):
        for j in range(i, n + 1):
            sum[i][j] = sum[i][j - 1] + a[j]

    # 점화식을 토대로 dy 배열 채우기
    for len in range(2, n + 1):
        for i in range(1, n - len + 2):
            j = i + len - 1
            dy[i][j] = 500 * 500 * 10000
            for k in range(i, j):
                dy[i][j] = min(dy[i][j], dy[i][k] + dy[k + 1][j] + sum[i][j])

    print(dy[1][n])

T = int(si())
for _ in range(T):
    solve()
