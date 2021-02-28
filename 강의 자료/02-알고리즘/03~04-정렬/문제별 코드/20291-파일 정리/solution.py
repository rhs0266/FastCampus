import sys
n = int(sys.stdin.readline())

ext = []
for _ in range(n):
    ext.append(sys.stdin.readline().strip().split('.')[1])

ext.sort()

i = 0
while i < n:
    cnt = 1
    for j in range(i + 1, n):
        if ext[j] == ext[i]: 
            cnt += 1
            i += 1
        else:
            break
    print(ext[i], cnt)
    i += 1