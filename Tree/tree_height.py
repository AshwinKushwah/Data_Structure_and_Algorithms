"""
Python program to calculate height of tree
"""


class Node:
    # Create node for binary tree
    def __init__(self, v):
        self.value = v
        self.left = None
        self.right = None


def tree_height(node):
    if node is None:
        return 0

    return max(tree_height(node.left), tree_height(node.right)) + 1

if __name__ == "__main__":
    """
    Creating Tree
        1
       / \
      2   3
     / \
    4   5
    """
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    h = tree_height(root)
    print("Height of tree : " + str(h))  # Output: Height of tree : 3
