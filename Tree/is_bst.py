"""
Python program to check whether given tree is binary search tree(BST) or not
[BST details - https://en.wikipedia.org/wiki/Binary_search_tree]
"""


class Node:
    # Create node for binary tree
    def __init__(self, v):
        self.value = v
        self.left = None
        self.right = None


def inorder_traversal(node, arr):
    if node is None:
        return None

    inorder_traversal(node.left, arr)
    arr.append(node.value)
    inorder_traversal(node.right, arr)


def is_bst(node):
    """
    return true if given tree is a valid bst else return false
    """
    arr = list()
    inorder_traversal(node, arr)
    # check if inorder traversal of tree is sorted i.e. strictly increasing
    for i in range(1, len(arr)):
        if arr[i] <= arr[i - 1]:
            return False

    return True


if __name__ == "__main__":
    """
    Creating Tree
        4
       / \
      2   5
     / \
    1   3
    """
    root = Node(4)
    root.left = Node(2)
    root.right = Node(5)
    root.left.left = Node(1)
    root.left.right = Node(3)

    print(is_bst(root))  # Output: True
