"""
Program for level order traversal of a binary tree
"""


class Node:
    # Create node for binary tree
    def __init__(self, v):
        self.value = v
        self.left = None
        self.right = None


def levelorder_traversal(root):
    queue = list()
    queue.append(root)
    while len(queue):
        curr_node = queue.pop(0)
        print(curr_node.value)
        if curr_node.left:
            queue.append(curr_node.left)
        if curr_node.right:
            queue.append(curr_node.right)


if __name__ == "__main__":
    """
    Creating Tree
        1
       / \
      2   3
     / \   \
    4   5   6
    """
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.right = Node(6)

    levelorder_traversal(root)  # Output: Height of tree : 1 2 3 4 5 6
