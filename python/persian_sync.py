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
from psetting import My_pSet


Form = uic.loadUiType(os.path.join(os.getcwd(), 'persian.ui'))[0]

class persian(Form , QMainWindow):
    path = ''
    path2 = ''
    def __init__(self, parent=None):
        # super(persian,parent)
        Form.__init__(self)
        QMainWindow.__init__(self)
        self.setupUi(self)
        self.pushButton_3.clicked.connect(self.get_Path)
        self.pushButton_4.clicked.connect(self.get_path_two)
        self.pushButton_2.clicked.connect(self.synchronize)
        self.pushButton.clicked.connect(self.load_project_structure)
        self.pushButton.clicked.connect(self.load_project_structure2)
        self.toolButton_10.clicked.connect(self.swap)
        self.pushButton_5.clicked.connect(self.sync_every_day)
        self.toolButton_6.clicked.connect(self.open_set)
        self.toolButton_7.clicked.connect(self.open_set)
        self.toolButton_8.clicked.connect(self.open_set)
        self.toolButton_4.clicked.connect(self.rl_sync)
        self.toolButton_5.clicked.connect(self.lr_sync)


    def get_Path(self):
        persian.path = QFileDialog.getExistingDirectory(self,"Select")
        print(persian.path)
        source(persian.path)
        self.comboBox.addItem(persian.path)
        return persian.path


    def get_path_two(self):
        persian.path2 = QFileDialog.getExistingDirectory(self,"Select")
        print(persian.path2)
        target(persian.path2)
        self.comboBox_2.addItem(persian.path2)
        return persian.path2


    def load_project_structure(self):
        model = QFileSystemModel()
        model.setRootPath(persian.path)
        self.treeView.setModel(model)
        self.treeView.setRootIndex(model.index(persian.path))
        self.treeView.show()

    def load_project_structure2(self):
        model = QFileSystemModel()
        model.setRootPath(persian.path2)
        self.treeView_2.setModel(model)
        self.treeView_2.setRootIndex(model.index(persian.path2))
        self.treeView_2.show()

    def swap(self):
        temp = persian.path
        persian.path = persian.path2
        persian.path2 = temp
        self.load_project_structure()
        self.load_project_structure2()

    def loadDate(self):
        cnx = mysql.connector.connect(user = 'root', password = 'sha00187', host= '127.0.0.1', port = '3306', database = 'sync')
        cursor = cnx.cursor(buffered=True)
        cursor.execute("DROP TABLE IF EXISTS source")
        result = cursor.execute("SELECT * FROM source")
        self.tableWidget.setRowCount(0)
        for row_num, row_data in enumerate(result):
            self.tableWidget.insertRow(row_num)
            for col_num, col_data in enumerate(row_data):
                self.tableWidget.setItem(row_num, col_num, QtWidgets.QTableWidgetItem(str(col_data)))
        cnx.autocommit(True)
        cursor.close()
        cnx.close()

    def synchronize(self):
        Dispatch.way = 2
        my_dispatch = Dispatch('aaron')
        node1 = Node(persian.path, 'node1')
        node2 = Node(persian.path2, 'node2')
        my_dispatch.add_node(node1)
        my_dispatch.add_node(node2)
        my_dispatch.compare_nodes()
        print ('Total files copied ' + str(my_dispatch.file_copied_count))
        print ('Total folders copied ' + str(my_dispatch.folder_copied_count))
        self.label.setText('Total files copied ' + str(my_dispatch.file_copied_count) + '\n' +'Total folders copied ' + str(my_dispatch.folder_copied_count))


    def lr_sync(self):
        Dispatch.way = 1
        my_dispatch = Dispatch('aaron')
        node1 = Node(persian.path, 'node1')
        node2 = Node(persian.path2, 'node2')
        my_dispatch.add_node(node1)
        my_dispatch.add_node(node2)
        my_dispatch.compare_nodes()
        print ('Total files copied ' + str(my_dispatch.file_copied_count))
        print ('Total folders copied ' + str(my_dispatch.folder_copied_count))
        self.label.setText('Total files copied ' + str(my_dispatch.file_copied_count) + '\n' +'Total folders copied ' + str(my_dispatch.folder_copied_count))


    def rl_sync(self):
        Dispatch.way = -1
        my_dispatch = Dispatch('aaron')
        node1 = Node(persian.path, 'node1')
        node2 = Node(persian.path2, 'node2')
        my_dispatch.add_node(node1)
        my_dispatch.add_node(node2)
        my_dispatch.compare_nodes()
        print ('Total files copied ' + str(my_dispatch.file_copied_count))
        print ('Total folders copied ' + str(my_dispatch.folder_copied_count))
        self.label.setText('Total files copied ' + str(my_dispatch.file_copied_count) + '\n' +'Total folders copied ' + str(my_dispatch.folder_copied_count))



    def open_new_dialog(self):
        self.nd = MainWindow(self)
        self.nd.show()

    def open_set(self):
        self.s = My_pSet(self)
        self.s.show()

    def sync_every_day(self):
        threading.Timer(3600.0, self.synchronize).start()


if __name__=="__main__":

    app = QApplication(sys.argv)
    w1 = persian()
    w1.show()
    sys.exit(app.exec_())
