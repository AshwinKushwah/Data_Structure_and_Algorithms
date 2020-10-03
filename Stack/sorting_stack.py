def sorted(s):
    stack1=[]
    stack2=[]
    while(s):
        p=s.pop()
        if len(stack1)==0:
            stack1.append(p)
        else:
            while(len(stack1)>0 and stack1[-1]<=p):
                stack2.append(stack1.pop())
            stack1.append(p)
            while(stack2):
                stack1.append(stack2.pop())
    for i in range(len(stack1)):
        s.append(stack1[i])
    

n = int(input())
arr = list(map(int, input().strip().split()))
sorted(arr)
for e in range(len(arr)):
    print(arr.pop(0), end=" ")
print()