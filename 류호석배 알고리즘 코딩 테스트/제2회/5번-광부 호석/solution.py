import sys

n, c = map(int, sys.stdin.readline().strip().split())
info = []
seq_x = []
seq_y = []
for i in range(n):
	x, y, v = map(int, sys.stdin.readline().strip().split())
	info.append((x, y, v))
	seq_x.append((x, i))
	seq_y.append((y, i))
seq_x.sort()
seq_y.sort()
seq_y.reverse()

res = 0
now = 0
cnt = 0
w = 0
h = 0
while w < n and h < n:
	if cnt < c:
		now_x = seq_x[w][0]
		while w < n and now_x == seq_x[w][0]:
			if info[seq_x[w][1]][1] > seq_y[h][0]:
				w += 1
				continue
			now += info[seq_x[w][1]][2]
			cnt += 1
			w += 1
	else:
		now_y = seq_y[h][0]
		while h < n and now_y == seq_y[h][0]:
			if info[seq_y[h][1]][0] >= seq_x[w][0]:
				h += 1
				continue
			now -= info[seq_y[h][1]][2]
			cnt -= 1
			h += 1
	if cnt <= c:
		res = max(res, now)
print(res)