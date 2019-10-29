"""
Python program to reverse a string using stack
"""


def reverse_string(st):
    """
    return a string in reverse form
    """
    stack = list()
    # Push each character into stack
    for ch in st:
        stack.append(ch)

    rev = ""
    # Pop each character one by one until stack is not empty
    while len(stack):
        rev += stack.pop()

    return rev


if __name__ == "__main__":
    st = "Test String"
    rev = reverse_string(st)
    print(rev)  # Output: gnirtS tseT
