import sys
sys.setrecursionlimit(100005)
si = sys.stdin.readline

Q = int(si())
dy = [0] * (100005)

# dy[i] := i 를 1, 2, 3의 합으로 표현하는 방법
# dy[0] 은 사실 문제 정의 상 말이 안되지만, 이후 점화식을 간단하게 적용하기 위해서
# "아무것도 안 더한다"는 것을 하나의 경우로 생각해줘서 1을 적어준다.
# 이를 통해서 dy[1, 2, 3]에 대해서도 일관성있는 점화식을 작성할 수 있기 때문이다.
# 이게 불편하다면 dy[1, 2, 3] 에 대해 모두 값을 적어주고 시작해도 상관없다.
dy[0] = 1
for i in range(1, 100001):
    dy[i] = dy[i - 1]  # 마지막에 1을 더하는 경우의 수
    if i >= 2: dy[i] += dy[i - 2]  # 마지막에 1을 더하는 경우의 수
    if i >= 3: dy[i] += dy[i - 3]  # 마지막에 1을 더하는 경우의 수
    dy[i] %= 1000000009

for _ in range(Q):
    x = int(si())
    res = 0
    # 홀수 개를 더한 경우
    for mid in range(1, 4):  # 가운데에 mid 를 더한 상황
        if x - mid >= 0 and (x - mid) % 2 == 0:  # 양쪽이 대칭을 이루게 더하기 위함
            res += dy[(x - mid) // 2]
    
    # 짝수 개를 더한 경우 (사실상 위에서 mid 가 0 인 경우. 즉, for loop을 0 부터 시작해도 됨)
    if x % 2 == 0:
        res += dy[x // 2]
    
    res %= 1000000009

    print(res)
