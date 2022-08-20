import requests
import threading
from bs4 import BeautifulSoup
import re
import os
import time

head = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36"
}  # 把浏览器的User-Agent贴进来，这里head也是一个字典
f = open("123321.txt", "a+", encoding='utf-8')


def gett(url):
    f = open("123321.txt", "a+", encoding='utf-8')
    r = requests.get(url=url, headers=head)  # requests标准形式
    soup = BeautifulSoup(r.text, "html.parser")
    temp = soup.select(
        '.bg6 .mlfy_main #mlfy_main_text p'
    )
    if url.find("_")==-1:
        f.write()
    for x in range(0,len(temp)-1):
        ss=str(temp[x])
        ss=ss.replace('<p>','')
        ss=ss.replace('</p>','\n')
        print(ss,end='')
    section_name = temp[0] + ' ' + temp[1]
    print(section_name)
    f.write(section_name + '\n')
    temp = soup.select(
        '.relative.color32.pt-read.mt20 .size16.lh150.plr15.pt10.relative.pt-read-cont #pt-pop'
    )[0].text
    section_text = temp.split()
    for x in section_text:
        f.write(x + '\n')
    return re.findall("var nextpage=\"(.*?)\"",r.text)[0]

url = "https://www.23qb.com/book/2385/3335719_2.html"
a = gett(url)
while a != "none":
    time.sleep(1)
    a = gett("https://www.23qb.com" + a)
