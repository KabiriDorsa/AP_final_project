import sys
from PyQt5 import uic
import os
from PyQt5.QtWidgets import QApplication,QMainWindow, QAction ,QFileSystemModel , QTableWidget, QTreeView ,QFileDialog, QTreeView
from sync import Node, Dispatch
from PyQt5 import QtWidgets
import mysql.connector
from emaildialog import MainWindow
from main import source, target
import threading
from setting import My_Set
from persian_sync import persian


Form = uic.loadUiType(os.path.join(os.getcwd(), 'sync.ui'))[0]

class My_Sync(Form , QMainWindow):
    path = ''
    path2 = ''
    cnx = mysql.connector.connect(user = 'root', password = 'sha00187', host= '127.0.0.1', port = '3306', database = 'sync')
    cursor = cnx.cursor(buffered=True)
    def __init__(self, parent=None):
        super(My_Sync, parent)
        Form.__init__(self)
        QMainWindow.__init__(self)
        self.setupUi(self)
        self.pushButton_3.clicked.connect(self.get_Path)
        self.pushButton_4.clicked.connect(self.get_path_two)
        self.pushButton_2.clicked.connect(self.synchronize)
        self.pushButton_2.clicked.connect(self.open_new_dialog)
        self.pushButton.clicked.connect(self.load_project_structure)
        self.pushButton.clicked.connect(self.load_project_structure2)
        self.toolButton_10.clicked.connect(self.swap)
        self.pushButton_5.clicked.connect(self.sync_every_day)
        self.toolButton_6.clicked.connect(self.open_set)
        self.toolButton_7.clicked.connect(self.open_set)
        self.toolButton_8.clicked.connect(self.open_set)
        self.action.triggered.connect(self.language)
        self.toolButton_4.clicked.connect(self.rl_sync)
        self.toolButton_5.clicked.connect(self.lr_sync)

    def get_Path(self):
        My_Sync.path = QFileDialog.getExistingDirectory(self,"Select")
        print(My_Sync.path)
        source(My_Sync.path)
        self.comboBox.addItem(My_Sync.path)
        return My_Sync.path


    def get_path_two(self):
        My_Sync.path2 = QFileDialog.getExistingDirectory(self,"Select")
        print(My_Sync.path2)
        target(My_Sync.path2)
        self.comboBox_2.addItem(My_Sync.path2)
        return My_Sync.path2

    #for comparing
    def load_project_structure(self):
        model = QFileSystemModel()
        model.setRootPath(My_Sync.path)
        self.treeView.setModel(model)
        self.treeView.setRootIndex(model.index(My_Sync.path))
        self.treeView.show()

    def load_project_structure2(self):
        model = QFileSystemModel()
        model.setRootPath(My_Sync.path2)
        self.treeView_2.setModel(model)
        self.treeView_2.setRootIndex(model.index(My_Sync.path2))
        self.treeView_2.show()

    #swap source and target directory
    def swap(self):
        temp = My_Sync.path
        My_Sync.path = My_Sync.path2
        My_Sync.path2 = temp
        self.load_project_structure()
        self.load_project_structure2()

    def synchronize(self):
        Dispatch.way = 2
        my_dispatch = Dispatch('aaron')
        node1 = Node(My_Sync.path, 'node1')
        node2 = Node(My_Sync.path2, 'node2')
        my_dispatch.add_node(node1)
        my_dispatch.add_node(node2)
        my_dispatch.compare_nodes()
        print ('Total files copied ' + str(my_dispatch.file_copied_count))
        print ('Total folders copied ' + str(my_dispatch.folder_copied_count))
        self.label.setText('Total files copied ' + str(my_dispatch.file_copied_count) + '\n' +'Total folders copied ' + str(my_dispatch.folder_copied_count))


    #left to right sync
    def lr_sync(self):
        Dispatch.way = 1
        my_dispatch = Dispatch('aaron')
        node1 = Node(My_Sync.path, 'node1')
        node2 = Node(My_Sync.path2, 'node2')
        my_dispatch.add_node(node1)
        my_dispatch.add_node(node2)
        my_dispatch.compare_nodes()
        print ('Total files copied ' + str(my_dispatch.file_copied_count))
        print ('Total folders copied ' + str(my_dispatch.folder_copied_count))
        self.label.setText('Total files copied ' + str(my_dispatch.file_copied_count) + '\n' +'Total folders copied ' + str(my_dispatch.folder_copied_count))

    #right to left sync
    def rl_sync(self):
        Dispatch.way = -1
        my_dispatch = Dispatch('aaron')
        node1 = Node(My_Sync.path, 'node1')
        node2 = Node(My_Sync.path2, 'node2')
        my_dispatch.add_node(node1)
        my_dispatch.add_node(node2)
        my_dispatch.compare_nodes()
        print ('Total files copied ' + str(my_dispatch.file_copied_count))
        print ('Total folders copied ' + str(my_dispatch.folder_copied_count))
        self.label.setText('Total files copied ' + str(my_dispatch.file_copied_count) + '\n' +'Total folders copied ' + str(my_dispatch.folder_copied_count))


    #email dialog
    def open_new_dialog(self):
        self.nd = MainWindow(self)
        self.nd.show()

    #change language
    def language(self):
        self.hide()
        self.p = persian(self)
        self.p.show()

    #open setting window
    def open_set(self):
        self.s = My_Set(self)
        self.s.show()

    #change the timing of synchronize
    def sync_every_day(self):
        threading.Timer(3600.0, self.synchronize).start()


if __name__=="__main__":

    app = QApplication(sys.argv)
    w = My_Sync()
    w.show()
    sys.exit(app.exec_())
