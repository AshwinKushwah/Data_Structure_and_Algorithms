"""
Implementation of various tree traversal methods
"""


class Node:
    # Create node for binary tree
    def __init__(self, v):
        self.value = v
        self.left = None
        self.right = None


def preorder_traversal(node):
    """
    recursive implementation of preorder traversal in which root is processed before left and right child
    :param node: Node of a binary tree
    """
    if node is None:
        return None
    print(node.value)
    preorder_traversal(node.left)
    preorder_traversal(node.right)


def inorder_traversal(node):
    """
    recursive implementation of inorder traversal in which root is processed after left child and before right child
    :param node: Node of a binary tree
    """
    if node is None:
        return None

    inorder_traversal(node.left)
    print(node.value)
    inorder_traversal(node.right)


def postorder_traversal(node):
    """
    recursive implementation of postorder traversal in which root is processed after left and right child
    :param node: Node of a binary tree
    """
    if node is None:
        return None

    postorder_traversal(node.left)
    postorder_traversal(node.right)
    print(node.value)


if __name__ == "__main__":
    """
    Creating Tree
       2
      / \
     1   3
    """
    node = Node(2)
    node.left = Node(1)
    node.right = Node(3)

    # calling different traversal for the tree
    preorder_traversal(node)  # Output : 2 1 3
    inorder_traversal(node)  # Output : 1 2 3
    postorder_traversal(node)  # Output : 1 3 2
