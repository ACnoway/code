# 后端：https://quanxiaoshuo.com/
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
        self.layout = QtWidgets.QGridLayout()
        #预览四个边都预留20pixs的边界
        self.layout.setContentsMargins(20, 20, 20, 20)
        #网格之间设置10pixs的间隔
        self.layout.setSpacing(10)
        self.layout.setRowMinimumHeight(0, 30)
        self.search = QtWidgets.QLineEdit(self)
        self.search.setPlaceholderText("请输入要搜索的书名，回车进行搜索")
        self.search.setMinimumHeight(30)
        self.layout.addWidget(self.search, 0, 0)
        self.history = QtWidgets.QPushButton("阅读历史", self)
        self.layout.addWidget(self.history, 1, 0)
        self.exitt = QtWidgets.QPushButton("退出", self)
        self.exitt.clicked.connect(QtCore.QCoreApplication.instance().quit)
        self.layout.addWidget(self.exitt, 2, 0)
        self.setLayout(self.layout)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    a = main_UI()
    a.setup_UI()
    a.show_UI()
    app.exec_()
