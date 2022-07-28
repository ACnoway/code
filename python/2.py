import requests
import threading
from bs4 import BeautifulSoup
import re
import os
import time

head = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36"} # 把浏览器的User-Agent贴进来，这里head也是一个字典
f=open("烟雨楼.txt","a+",encoding='utf-8')
def gett(url):
    r = requests.get(url=url,headers=head) # requests标准形式
    soup=BeautifulSoup(r.text,"html.parser")
    temp=soup.select('.relative.color32.pt-read.mt20 .size18.w100.text-center.lh100.pt30.pb15')[0].text.split()
    section_name=temp[0]+' '+temp[1]
    print(section_name)
    f.write(section_name+'\n')
    temp=soup.select('.relative.color32.pt-read.mt20 .size16.lh150.plr15.pt10.relative.pt-read-cont #pt-pop')[0].text
    section_text=temp.split()
    for x in section_text:
        f.write(x+'\n')
    try:
        next_url=soup.select('.plr15.ptb10.size14.color62 .flex-wrp.w100.border-c .pt-nextchapter a')[0]['href']
    except:
        next_url="none"
    return next_url
url = "https://m.wxsy.net/novel/59751/read_48583353.html"
a=gett(url)
while a!="none":
    time.sleep(1)
    a=gett("https://m.wxsy.net"+a)