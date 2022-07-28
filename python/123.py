from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import sys
import requests
from bs4 import BeautifulSoup
import time

head = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36"
}  # 把浏览器的User-Agent贴进来，这里head也是一个字典
f = open("剑来.txt", "a+", encoding='utf-8')


class aUI(QWidget):

    def show_UI(self):
        self.show()

    def setup_UI(self):
        self.setFixedSize(500, 500)
        self.setWindowTitle("test")
        self.getnum = QPushButton("start", self)
        self.getnum.move(0, 0)
        self.getnum.resize(500, 100)
        self.getnum.clicked.connect(self.startt)
        self.jindutiao = QProgressBar(self)
        self.jindutiao.move(0, 150)
        self.jindutiao.resize(500, 30)
        self.jindutiao.setMinimum(0)
        self.jindutiao.setMaximum(999)
        self.jindutiao.setValue(0)
        self.text = ""
        self.showtext = QLabel(self)
        self.showtext.setWordWrap(True)
        self.showtext.setAlignment(Qt.AlignLeft | Qt.AlignTop)
        self.showtext.setMinimumSize(QSize(450, 100))
        self.showtext.move(200, 230)
        self.showtext.resize(450,100)
        self.scrollarea = QScrollArea(self)
        self.scrollarea.setWidget(self.showtext)
        self.scrollarea.setMinimumSize(QSize(450,100))
        self.scrollarea.setMaximumSize(QSize(450,100))
        self.showtext.setText(self.text)
        self.t = QElapsedTimer()

    def startt(self):
        url = "/book/17.html"
        cnt = 1
        while url != "none":
            url = self.get("http://www.jianlaixiaoshuo.com" + url)
            self.jindutiao.setValue(cnt)

            self.showtext.setText(self.text)
            self.showtext.move(200, 230)
            cnt += 1
            # 用qtimer的elapsedtimer实现time.sleep
            # 且不会堵塞线程，在停止的同时能够处理之前未处理完的任务
            self.t.start()
            while self.t.elapsed() < 5000:
                QCoreApplication.processEvents()

    def get(self, url):
        try:
            r = requests.post(url=url, headers=head)  # requests标准形式
        except:
            time.sleep(0.5)
            r = requests.post(url=url, headers=head)
        while not r:
            time.sleep(0.5)
            try:
                r = requests.post(url=url, headers=head)  # requests标准形式
            except:
                time.sleep(0.5)
                r = requests.post(url=url, headers=head)
        soup = BeautifulSoup(r.text, "html.parser")
        self.section_name = soup.select(
            '.container #main.article #BookCon.inner h1')[0].text
        self.section_text = soup.select(
            '.container #main.article #BookCon.inner #BookText')[0].text
        try:
            next_url = soup.select(
                '.container #main.article #BookCon.inner .link.xb a'
            )[2]['href']
        except:
            next_url = "none"
        print(self.section_name)
        self.text = self.text + '\n' + self.section_name + '\n' + self.section_text
        f.write(self.section_name + '\n')
        f.write(self.section_text + '\n')
        return next_url


if __name__ == "__main__":
    app = QApplication(sys.argv)
    a = aUI()
    a.setup_UI()
    a.show_UI()
    app.exec_()
