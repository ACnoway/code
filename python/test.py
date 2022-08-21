#from VipCode import *
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
f = open("testt.txt", "a+", encoding='utf-8')


def gett(url):
    f = open("testt.txt", "a+", encoding='utf-8')
    r = requests.get(url=url, headers=head)  # requests标准形式
    soup = BeautifulSoup(r.text, "html.parser")
    print((re.findall("<title>(.*?)_铅笔小说",str(soup.select('head title')[0]))[0]),end='')
    if url.find("_")==-1:
        f.write('\n'+(re.findall("<title>(.*?)_铅笔小说",str(soup.select('head title')[0]))[0])+"\n\n")
    temp = soup.select(
        '.bg6 .mlfy_main #mlfy_main_text p'
    )
    print("...",end='')
    for x in range(0,len(temp)-1):
        ss=str(temp[x])
        ss=ss.replace('<p>','')
        ss=ss.replace('</p>','\n')
        f.write(ss)
    print("...",end='')
    print("已完成")
    return re.findall("var nextpage=\"(.*?)\"",r.text)[0]

url = "https://www.23qb.com/book/2385/3335714.html"
a = gett(url)

while a != "":
    time.sleep(1)
    a = gett("https://www.23qb.com" + a)
