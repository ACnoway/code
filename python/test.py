from VipCode import *

class main_UI(PyQt5_QDialog):
    
    def show_UI(self):
        self.show()

    def setup_UI(self):
        self.setWindowTitle("test")
        self.setFixedSize(100,100)


if name=="__main__":
    app=QApplication()
    a=main_UI
    a.setup_UI()
    a.show_UI()
    app.exec_()