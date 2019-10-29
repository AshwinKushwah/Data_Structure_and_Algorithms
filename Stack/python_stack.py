class Stack:
    
    #Constructor 
    def __init__(self):
        self.stack = list()
        self.maxSize = 8
        self.top = 0
    
    #Adds element to the Stack
    def push(self,data):
        if self.top>=self.maxSize:
            return ("Stack Full!")
        self.stack.append(data)
        self.top += 1
        return True
        
    #Removes element from the stack
    def pop(self):
        if self.top<=0:
            return ("Stack Empty!")
        item = self.stack.pop()
        self.top -= 1
        return item
        
    #Size of the stack
    def size(self):
        return self.top
