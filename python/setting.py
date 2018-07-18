import sys
from PyQt5 import uic
from PyQt5.QtWidgets import QApplication,QMainWindow ,QFileSystemModel , QTreeView ,QFileDialog, QTreeView
import os

Form = uic.loadUiType(os.path.join(os.getcwd(), 'set.ui'))[0]


class My_Set(Form , QMainWindow):
    def __init__(self, parent=None):
        super(My_Set, self).__init__(parent)
        Form.__init__(self)
        QMainWindow.__init__(self)
        self.setupUi(self)


if __name__=="__main__":
    app = QApplication(sys.argv)
    w = My_Set()
    w.show()
    sys.exit(app.exec_())