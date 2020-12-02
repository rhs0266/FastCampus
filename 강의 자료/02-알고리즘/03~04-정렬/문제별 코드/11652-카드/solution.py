import sys
n = int(sys.stdin.readline())
a = []

for i in range(n):
    a.append(int(sys.stdin.readline()))

a.sort()

mode = a[0]
modeCnt = 1
curCnt = 1

for i in range(1, n):
    if a[i] == a[i-1]:
        curCnt += 1
    else:
        curCnt = 1
    if modeCnt < curCnt:
        modeCnt = curCnt;
        mode = a[i]

print(mode)