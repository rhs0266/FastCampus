import sys
n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split(' ')))
operators = list(map(int, sys.stdin.readline().split(' ')))
min = 1e9
max = -1e9

def calculator(operand1, operator, operand2):
    if operator == 0:
        return operand1 + operand2
    if operator == 1:
        return operand1 - operand2
    if operator == 2:
        return operand1 * operand2
    if operator == 3:
        if operand1 < 0:
            return - ((-operand1) // operand2)
        else:
            return operand1 // operand2

def rec_func(k, value):
    if k == n - 1:
        global min, max
        min = min if min < value else value
        max = max if max > value else value
    else:
        global operators
        for cand in range(4):
            if operators[cand] >= 1:
                operators[cand] -= 1
                rec_func(k + 1, calculator(value, cand, nums[k + 1]))
                operators[cand] += 1

rec_func(0, nums[0])
print(max)
print(min)