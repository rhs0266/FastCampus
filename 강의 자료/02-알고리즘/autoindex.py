import os
from lxml import html
import requests

def get_dir_list(path):
    return [p for p in os.listdir(path) if os.path.isdir(p)]

def get_file_list(path):
    return [p for p in os.listdir(path) if os.path.isfile(p)]

def get_number(str):
    res = ''.join(list(filter(lambda x: '0'<=x<='9', str)))
    if res:
        return res
    return None

def get_code_dir(path, numberStr):
    for p in os.listdir(path):
        p = path + '/' + p
        if not os.path.isdir(p):
            continue
        if numberStr not in p:
            continue
        req = ['solution.cpp', 'solution.java', 'solution.py']
        if all(r in os.listdir(p) for r in req):
            return p.replace(' ', '%20')
    return False

for chapter in get_dir_list('./'):
    md_path = os.path.join(chapter, 'README.md')
    new_md = []
    with open(md_path, "r", encoding="UTF8") as f:
        for line in f.readlines():
            line = line.strip()
            row = line.split('|')
            numberStr : str = get_number(row[2])
            if numberStr:
                res = requests.get('http://boj.kr/' + numberStr)
                res.raise_for_status()
                res.encoding = 'UTF-8'
                tree = html.fromstring(res.text)
                title = tree.xpath('//title/text()')[0].split(' ', 1)[1]
                row[1] = title
                codePath = get_code_dir(chapter+'/문제별 코드', numberStr)
                row[2] = f"[링크](http://boj.kr/{numberStr})"
                if codePath:
                    row[3] = f'[링크](https://github.com/rhs0266/FastCampus/tree/main/%EA%B0%95%EC%9D%98%20%EC%9E%90%EB%A3%8C/02-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/{codePath})'
                else:
                    if len(row[3]) < 10:
                        row[3] = f'[링크]'
            new_md.append('|'.join(row))
    
    with open(md_path, "w", encoding="UTF8") as f:
        f.write('\n'.join(new_md))
