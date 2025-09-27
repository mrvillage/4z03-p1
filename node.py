class Node:
    def __init__(self, value, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

class NodeSlots:
    __slots__ = ['value', 'left', 'right']
    def __init__(self, value, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

def sum(node):
    acc = node.value
    if node.left is not None:
        acc += sum(node.left)
    if node.right is not None:
        acc += sum(node.right)
    return acc

tree = Node(1, Node(2), Node(3))
total = sum(tree) # 6
tree.right = None # tree is now Node(1, Node(2), None)
tree = tree.left # tree is now Node(2)
