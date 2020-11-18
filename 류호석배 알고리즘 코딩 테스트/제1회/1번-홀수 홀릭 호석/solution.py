# Input & Init
n = int(input())
ans_min = 0x7fffffff
ans_max = 0

def get_odd_cnt(x: int):
    res = 0
    while (x > 0):
        res += x % 2
        x = x // 10
    return res

def dfs(x: int, total_odd_cnt: int):
    if x <= 9:
        global ans_max, ans_min
        ans_min = min(ans_min, total_odd_cnt)
        ans_max = max(ans_max, total_odd_cnt)
        return

    if x <= 99:
        nx = x//10 + x%10
        dfs(nx, get_odd_cnt(nx) + total_odd_cnt)
        return
    
    x = str(x)
    for i in range(0, len(x) - 2):
        for j in range(i + 1, len(x) - 1):
            x1 = x[: i + 1]
            x2 = x[i + 1 : j + 1]
            x3 = x[j + 1 :]

            nx = int(x1) + int(x2) + int(x3)
            dfs(nx, get_odd_cnt(nx) + total_odd_cnt)

dfs(n, get_odd_cnt(n))
print(ans_min, ans_max)