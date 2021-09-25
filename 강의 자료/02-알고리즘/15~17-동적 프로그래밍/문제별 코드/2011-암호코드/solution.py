import sys
si = sys.stdin.readline

a = si().strip()
n = len(a)

def check(A: chr, B: chr):  # 'AB' 라는 두 자리 숫자가 하나의 수로 해독이 가능한가?
    if A == '0': return False
    if A == '1': return True
    if A >= '3': return False
    return B <= '6'

dy = [0] * n

# 초기값 구하기
if a[0] != '0':
    dy[0] = 1

# 점화식을 토대로 Dy 배열 채우기
for i in range(1, n):
    # i 번 숫자를 단독으로 해석 가능할 때
    if a[i] != '0':
        dy[i] = dy[i - 1]
    
    # i - 1번과 i 번 숫자를 하나의 문자로 해석 가능할 때
    if check(a[i - 1], a[i]):
        if i >= 2: dy[i] += dy[i - 2]
        else: dy[i] += 1
        dy[i] %= 1000000

print(dy[n - 1])