
class Node:

    def __init__(self, key=None, size=1, height=1):
        self.key = key
        self.size = size
        self.left = None
        self.right = None
        self.height = height

    def get_height(

    def get_balance(self):
        if self.left is None and self.right is None:
            return 0
        if self.left is None:
            return -self.right.height
        if self.right is None:
            return self.left.height
        return self.left.height - self.right.height

    def set_balance(self, key):
        balance = self.get_balance()
        if balance > 1 and self.left and key < self.left.key:
            self.right_rotate()
        if balance < -1 and self.right and key > self.right.key:
            self.left_rotate()
        if balance > 1 and self.left and key > self.left.key:
            self.left = self.left.left_rotate()
            self.right_rotate()
        if balance < -1 and self.right and key < self.right.key:
            self.right = self.right.right_rotate()
            self.left_rotate()


class OrderStatisticTree:

    def __init__(self):
        self.root = None

    def _insert(self, node, key):
        if node is None:
            return Node(key=key)
        if key > node.key:
            node.right = self._insert(node.right, key)
        else:
            node.left = self._insert(node.left, key)
        if node.right is None: 
            node.height = node.left.height + 1
            node.size = node.left.size + 1
        elif node.left is None: 
            node.height = node.right.height + 1
            node.size = node.right.size + 1
        else: 
            node.height = max(node.left.height, node.right.height) + 1
            node.size = node.left.size + node.right.size + 1
        node.set_balance(key)
        return node

    def insert(self, k):
        self.root = self._insert(self.root, k)

