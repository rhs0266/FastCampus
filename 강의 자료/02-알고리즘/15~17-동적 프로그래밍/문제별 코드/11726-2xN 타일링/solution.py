import heapq
import sys
si = sys.stdin.readline

n = int(si())

dy = [0] * (n + 2)
# 초기값 채우기
dy[1], dy[2] = 1, 2

# 점화식을 토대로 dy 배열 채우기
for i in range(3, n + 1):
    dy[i] = (dy[i - 1] + dy[i - 2]) % 10007

print(dy[n])
