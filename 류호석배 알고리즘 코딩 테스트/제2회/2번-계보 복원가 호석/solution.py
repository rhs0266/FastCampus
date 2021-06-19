import sys
a_str, b_str = sys.stdin.readline().strip().split()

a_min_base = 2
b_min_base = 2

for x in a_str:
	if x.isalpha():
		a_min_base = max(a_min_base, ord(x) - ord('a') + 11)
	if x.isdigit():
		a_min_base = max(a_min_base, ord(x) - ord('0') + 1)

for x in b_str:
	if x.isalpha():
		b_min_base = max(b_min_base, ord(x) - ord('a') + 11)
	if x.isdigit():
		b_min_base = max(b_min_base, ord(x) - ord('0') + 1)

x = -1
a = -1
b = -1
cnt = 0
for i in range(a_min_base, 37):
	for j in range(b_min_base, 37):
		a_num = int(a_str, i)
		b_num = int(b_str, j)
		if a_num >= 2**63 or b_num >= 2**63:
			continue
		if a_num == b_num and i != j:
			x = a_num
			a = i
			b = j
			cnt += 1

if cnt==0:
	print('Impossible')
elif cnt>1:
	print('Multiple')
else:
	print(x, a, b)