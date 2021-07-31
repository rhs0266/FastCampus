import sys
sys.setrecursionlimit(500005)
si = sys.stdin.readline

n, Q = map(int, si().split())


def pro():
    # 사고 싶은 땅에서 시작해서 루트 땅까지 올라오면서 정답을 찾으면 편하다.
    # 왜냐하면 부모 노드는 찾기 쉽기 때문이다.
    estate = [False] * (n + 1)
    for _ in range(Q):
        x = int(si())
        y = x
        res = 0
        while x:
            if estate[x]: res = x
            x //= 2
        estate[y] = True
        print(res)


if __name__ == "__main__":
    pro()
