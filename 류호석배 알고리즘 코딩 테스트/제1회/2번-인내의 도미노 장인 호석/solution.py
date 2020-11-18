import queue

# input & init
n, m, r = map(int, input().split())
domino = []
check = []
ddir = {'E': (0, 1), 'W': (0, -1), 'S': (1, 0), 'N': (-1, 0)}
for i in range(n):
  domino.append(list(map(int, input().split())))
  check.append([True] * m)

def attack(x, y, dir):
  global score
  if not check[x][y]:
    return
  dx, dy = ddir[dir]
  cnt = domino[x][y]
  while x >= 0 and y >= 0 and x < n and y < m and cnt >= 1:
    if check[x][y]:
      score += 1
      cnt = max(cnt - 1, domino[x][y] - 1)
    else:
      cnt = cnt - 1
    check[x][y] = False
    x += dx
    y += dy

score = 0
# simulation start
for i in range(r):
  # attack
  x, y, k = input().split()
  x = int(x) - 1
  y = int(y) - 1
  attack(x, y, k)

  # defense
  x, y = map(int, input().split())
  x -= 1
  y -= 1
  check[x][y] = True

# print
print(score)
for i in range(n):
  for j in range(m):
    print('S' if check[i][j] else 'F', end=' ')
  print()