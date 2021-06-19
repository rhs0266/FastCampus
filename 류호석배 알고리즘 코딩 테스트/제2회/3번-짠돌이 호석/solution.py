import sys

n1, m1 = map(int, sys.stdin.readline().strip().split())
pict1 = []
for i in range(n1):
	pict1.append(sys.stdin.readline().strip())

n2, m2 = map(int, sys.stdin.readline().strip().split())
pict2 = []
for i in range(n2):
	pict2.append(sys.stdin.readline().strip())

res = 40404
for _ in range(4):
	temp = [[0 for j in range(n2)] for i in range(m2)]
	for i in range(n2):
		for j in range(m2):
			temp[j][n2 - i - 1] = pict2[i][j]
	pict2 = temp
	n2, m2 = m2, n2
	for i in range(-51, 51):
		for j in range(-51, 51):
			pos = True
			for x in range(n1):
				for y in range(m1):
					if 0 <= x + i < n2 and 0 <= y + j < m2 and pict1[x][y] == '1' and pict2[x + i][y + j] == '1':
						pos = False
						break
				if not pos:
					break
			if pos:
				res = min(res, (max(n1 + i, n2) - min(0, i)) * (max(m1 + j, m2) - min(0, j)))
print(res)