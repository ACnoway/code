import requests
import threading
from bs4 import BeautifulSoup
import re
import os
import time

head = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36"} # 把浏览器的User-Agent贴进来，这里head也是一个字典
f=open("剑来.txt","a+",encoding='utf-8')
def get(url):
    try:
        r = requests.post(url=url,headers=head) # requests标准形式
    except:
        time.sleep(2)
        r = requests.post(url=url,headers=head)
    soup=BeautifulSoup(r.text,"html.parser")
    section_name=soup.select('.container #main.article #BookCon.inner h1')[0].text  
    section_text=soup.select('.container #main.article #BookCon.inner #BookText')[0].text 
    try:
        next_url=soup.select('.container #main.article #BookCon.inner .link.xb a')[2]['href']
    except:
        next_url="none"
    print(section_name)
    f.write(section_name+'\n')
    f.write(section_text+'\n')
    return next_url
url = "/book/17.html"
while url!="none":
    url=get("http://www.jianlaixiaoshuo.com"+url)