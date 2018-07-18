import os
import filecmp
import shutil
import pstats
import cProfile

class Dispatch:
    # way defined for left to right or right to left sync
    way = 2
    def __init__(self, name=''):
        self.name = name
        self.node_list = []
        self.file_copied_count = 0
        self.folder_copied_count = 0

    def add_node(self, node):
        self.node_list.append(node)

    def compare_nodes(self):
        nodeListLength = len(self.node_list)
        # For each node in the list
        for node in self.node_list:
            # If the list has another item after it, compare them
            if self.node_list.index(node) < len(self.node_list) - 1:
                node2 = self.node_list[self.node_list.index(node) + 1]
                print('\nComparing Node ' + str(self.node_list.index(node)) + ' and Node ' + str(self.node_list.index(node) + 1) + ':')
                # Passes the two root directories of the nodes to the recursive _compare_directories.
                self._compare_directories(node.root_path, node2.root_path)

    def _compare_directories(self, left, right):
        comparison = filecmp.dircmp(left, right)
        if comparison.common_dirs:
            for d in comparison.common_dirs:
                self._compare_directories(os.path.join(left, d), os.path.join(right, d))
        if comparison.left_only:
            if Dispatch.way != -1:
                self._copy(comparison.left_only, left, right)
        if comparison.right_only:
            if Dispatch.way != 1:
                self._copy(comparison.right_only, right, left)
        left_newer = []
        right_newer = []
        if comparison.diff_files:
            for d in comparison.diff_files:
                l_modified = os.stat(os.path.join(left, d)).st_mtime
                r_modified = os.stat(os.path.join(right, d)).st_mtime
                if l_modified > r_modified:
                    left_newer.append(d)
                else:
                    right_newer.append(d)
        self._copy(left_newer, left, right)
        self._copy(right_newer, right, left)

    def _copy(self, file_list, src, dest):
        for f in file_list:
            srcpath = os.path.join(src, os.path.basename(f))
            if os.path.isdir(srcpath):
                shutil.copytree(srcpath, os.path.join(dest, os.path.basename(f)))
                self.folder_copied_count = self.folder_copied_count + 1
                print ('Copied directory \"' + os.path.basename(srcpath) + '\" from \"' + os.path.dirname(srcpath) + '\" to \"' + dest + '\"')
            else:
                shutil.copy2(srcpath, dest)
                self.file_copied_count = self.file_copied_count + 1
                print ('Copied \"' + os.path.basename(srcpath) + '\" from \"' + os.path.dirname(srcpath) + '\" to \"' + dest + '\"')


class Node:
    def __init__(self, path, name=''):
        self.name = name
        self.root_path = os.path.abspath(path)
        self.file_list = os.listdir(self.root_path)

#default directory
if __name__ == "__main__":
    pr = cProfile.Profile()
    pr.enable()
    my_dispatch = Dispatch('aaron')
    node1 = Node('C:\\Users\\ASUS\\Desktop\\1', 'node1')
    node2 = Node('C:\\Users\\ASUS\\Desktop\\2', 'node2')
    my_dispatch.add_node(node1)
    my_dispatch.add_node(node2)
    my_dispatch.compare_nodes()
    print ('Total files copied ' + str(my_dispatch.file_copied_count))
    print ('Total folders copied ' + str(my_dispatch.folder_copied_count))
    pr.disable()
    p = pstats.Stats(pr)
    p.strip_dirs().sort_stats('time').print_stats()