# 전처리 과정 - 불 반전 갯수 계산
segment = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]
number = [[0 for _ in range(10)] for _ in range(10)]
for i in range(10):
    for j in range(10):
        xor = segment[i] ^ segment[j]
        while xor:
            number[i][j] += (xor % 2)
            xor //= 2

# 입출력 - 경우의 수 계산
n, k, p, x = map(int, input().split())
count = 0
for i in range(1, n + 1):
    reverse = 0
    temp_i = i
    temp_x = x
    for j in range(k):
        reverse += number[temp_i % 10][temp_x % 10]
        temp_i //= 10
        temp_x //= 10
    if 1 <= reverse <= p:
        count += 1
print(count)