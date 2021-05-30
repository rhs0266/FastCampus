import sys
input = sys.stdin.readline
m, n = map(int, input().split(' '))
chars = sorted(input().strip().split(' '))
used = [0] * n
selected = [0] * m

def is_vowel(x: str):
    return x in "aeiou"

def rec_func(k):
    if k == m:
        vowel, consonant = 0, 0
        for x in selected:
            if is_vowel(chars[x]):
                vowel += 1
            else:
                consonant += 1

        if (vowel >= 1) and (consonant >= 2):
            for x in selected:
                print(chars[x], end='')
            print()

    else:
        st = -1 if k == 0 else selected[k - 1]
        for i in range(st + 1, n):
            selected[k] = i
            rec_func(k + 1)
            selected[k] = 0

rec_func(0)