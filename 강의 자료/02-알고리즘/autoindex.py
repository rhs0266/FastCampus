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
        return int(res)
    return None

for chapter in get_dir_list('./'):
    md_path = os.path.join(chapter, '문제 리스트.md')
    new_md = []
    with open(md_path, "r") as f:
        for line in f.readlines():
            line = line.strip()
            row = line.split('|')
            number = get_number(row[2])
            if number:
                res = requests.get('http://boj.kr/' + str(number))
                res.raise_for_status()
                res.encoding = 'UTF-8'
                tree = html.fromstring(res.text)
                title = tree.xpath('//title/text()')[0].split(' ', 1)[1]
                row[1] = title
                code = get_code_dir()
                if code:
                    row[3] = f'[링크]({code})'
                else:
                    row[3] = f'[링크]'
            new_md.append('|'.join(row))
    
    with open(md_path, "w") as f:
        f.write('\n'.join(new_md))