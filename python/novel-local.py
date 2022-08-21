import requests
import re
from bs4 import BeautifulSoup
import sys
from PyQt5 import QtWidgets
from PyQt5 import QtCore

head = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36"
}  # 把浏览器的User-Agent贴进来，这里head也是一个字典


class main_UI(QtWidgets.QWidget):

    def show_UI(self):
        self.show()

    def setup_UI(self):
        self.resize(500, 700)
        self.setWindowTitle("本地小说阅读器")
        

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    a = main_UI()
    a.setup_UI()
    a.show_UI()
    app.exec_()
