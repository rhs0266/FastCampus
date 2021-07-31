import sys
sys.setrecursionlimit(10005)
si = sys.stdin.readline
a = []

def input():
    while True:
        line = si()
        if not line:
            break
        a.append(int(line))


def traverse(l, r):
    if l > r: return
    mid = r
    for i in range(l + 1, r + 1):
        if a[i] > a[l]:
            mid = i - 1
            break
    
    traverse(l + 1, mid)
    traverse(mid + 1, r)
    print(a[l])


def pro():
    traverse(0, len(a) - 1)


if __name__ == "__main__":
    input()
    pro()