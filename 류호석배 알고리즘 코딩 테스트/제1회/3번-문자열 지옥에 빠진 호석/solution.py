tile=[]
find=dict()
dx=[1,1,1,0,0,-1,-1,-1]
dy=[1,0,-1,1,-1,1,0,-1]

# dfs function
def dfs(x, y, dstr):
  find[dstr] = find.get(dstr, 0) + 1
  if len(dstr)==5:
    return
  for i in range(8):
    nx=(x+dx[i]+n)%n
    ny=(y+dy[i]+m)%m
    dfs(nx, ny, dstr+tile[nx][ny])

# input
n, m, k = map(int, input().split())
for i in range(n):
  tile.append(input())

# dfs for tile
for i in range(n):
  for j in range(m):
    dfs(i, j, tile[i][j])

# print
for i in range(k):
  print(find.get(input(), 0))