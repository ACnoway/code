import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import time


class test_UI(QWidget):

    def show_UI(self):
        self.show()

    def setup_UI(self):
        self.setWindowTitle("test")
        self.setFixedSize(500, 300)
        self.text = "1\n2\n3\n2\n1\n3\n1\n2\n3\n1\n2\n3\n2\n1\n3\n2\n1\n3\n2\n1\n3\n2\n1\n3\n2\n1\n3\n2\n1\n3\n2\n1\n3\n2\n1\n3\n"
        self.showtext = QLabel(self)
        self.showtext.setWordWrap(True)
        self.showtext.setAlignment(Qt.AlignLeft | Qt.AlignTop)
        self.showtext.setMinimumSize(QSize(50, 10))
        self.showtext.move(0, 100)
        self.showtext.resize(500, 300)
        self.scrollarea = QScrollArea(self)
        self.scrollarea.setWidget(self.showtext)
        self.scrollarea.setMinimumSize(QSize(500, 300))
        self.scrollarea.setMaximumSize(QSize(500, 300))
        self.showtext.setText(self.text)
        self.change=QPushButton("change",self)
        self.change.clicked.connect(self.changee)
        

    def changee(self):
        self.text = "asd\n2\n3\n2\nasd\n3\nasd\n2\n3\nasd\n2\n3\n2\nasd\n3\n2\nasd\n3\n2\nasd\n3\n2\nasd\n3\n2\nasd\n3\n2\nasd\n3\n2\nasd\n3\n2\nasd\n3\n"
        self.showtext.setText(self.text)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    a = test_UI()
    a.setup_UI()
    a.show_UI()
    app.exec_()