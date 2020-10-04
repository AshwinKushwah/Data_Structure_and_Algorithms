# Note :- This code is also useful for find a mid point of linikedlist for that you have to make condition when fast pointer reach at end of linkedlist 
# at that time slow pointer is at the mid of linkedlist

class Node:
    def __init__(self , dataval=None):
        self.data = dataval
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    # print linkedlist
    def listprint(self):
        printval = self.head
        while printval is not None:
            print(printval.data)
            printval = printval.next

# Another Approach :
# using fast and Slow Pointer

def Iscycle(list):
    fast = list.head
    slow = list.head
    while(fast is not None and fast.next is not None):

        slow = slow.next  # 1 step jump
        fast = fast.next.next  # 2 step jump

        if(slow == fast):
            return True
    return False

# Creation linked list 1 3 7 4 10 2

list = LinkedList()
list.head = Node(1)
n2 = Node(3)
n3 = Node(7)
n4 = Node(4)
n5 = Node(10)
n6 = Node(2)

list.head.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n5.next = n6
n6.next = n4 # cycle

# Return true or False
print(Iscycle(list))
