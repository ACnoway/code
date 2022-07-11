import requests

header = {
    "cookie":
    "__client_id=006c4a570fed591fa85bd424127f8057defa2bd8; _uid=490439",
    "user-agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36 Edg/91.0.864.64"
}

url = "https://www.luogu.com.cn/"
req = requests.get(url=url,headers=header)
print(req.text)
