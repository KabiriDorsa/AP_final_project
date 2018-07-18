import sys
from sendmail import send_mail
from PyQt5.QtCore import QSize
from PyQt5.QtGui import QMovie, QPainter, QPixmap
from PyQt5 import QtGui
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QWidget, QTextBrowser, QLabel, QLineEdit


class UIWindow(QWidget):
    def __init__(self, parent=None):
        super(UIWindow, self).__init__(parent)
        self.resize(QSize(600, 750))
        self.ToolsBTN = QPushButton('Ok', self)
        self.ToolsBTN.resize(100, 40)
        self.ToolsBTN.move(200, 450)

        self.dialog = QLabel(parent)
        self.dialog.setText('Please enter your Email')
        newfont = QtGui.QFont("Times", 15, QtGui.QFont.Bold)
        self.dialog.setFont(newfont)
        self.dialog.resize(250, 40)
        self.dialog.move(50, 20)

        self.dialog2 = QLabel(parent)
        self.dialog2.setText('Complete!')
        newfont = QtGui.QFont("Times", 15, QtGui.QFont.Bold)
        self.dialog2.setFont(newfont)
        self.dialog2.resize(100, 40)
        self.dialog2.move(200, 400)
        self.dialog2.setVisible(False)

        self.mail = QLineEdit(parent)
        self.mail.resize(150, 30)
        self.mail.move(320, 22)


        self.ToolsBTN.clicked.connect(self.savemail)

    def savemail(self):
        send_mail("jordanalex733@gmail.com", self.mail.text(), 'sync', 'this email sent from best-sync group',"Expenses01.xlsx", 'smtp.gmail.com', 587)
        self.dialog2.setVisible(True)


class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        self.setGeometry(50, 50, 600, 750)
        self.setFixedSize(500, 500)
        self.startUIWindow()

        self.movie = QMovie("mail.gif")
        self.movie.frameChanged.connect(self.repaint)
        self.movie.start()


    def startUIWindow(self):
        self.Window = UIWindow(self)
        self.setWindowTitle("Email Dialog")
        self.show()

    def paintEvent(self, event):
        currentFrame = self.movie.currentPixmap()
        frameRect = currentFrame.rect()
        frameRect.moveCenter(self.rect().center())
        if frameRect.intersects(event.rect()):
            painter = QPainter(self)
            painter.drawPixmap(frameRect.left(), frameRect.top(), currentFrame)


def email_main():
    app = QApplication(sys.argv)
    w = MainWindow()
    sys.exit(app.exec_())

if __name__ == '__main__':
    email_main()