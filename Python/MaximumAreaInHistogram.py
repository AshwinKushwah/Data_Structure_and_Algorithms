heights=[int(x) for x in input().split()]
stack=[]
left=[]
right=[]
for i in range(len(heights)):
    if stack==[]:
        left.append(-1)
    elif stack[-1][0]<heights[i]:
        left.append(stack[-1][1])
    else:
        while len(stack)!=0 and stack[-1][0]>=heights[i]:
            stack.pop(-1)
        if len(stack)==0:
            left.append(-1)
        else:
            left.append(stack[-1][1])
    stack.append([heights[i],i])
#print(left)
stack=list()
for i in range(len(heights)-1,-1,-1):
    if stack==[]:
        right.append(len(heights))
    elif stack[-1][0]<heights[i]:
        right.append(stack[-1][1])
    else:
        while len(stack)!=0 and stack[-1][0]>=heights[i]:
            stack.pop(-1)
        if len(stack)==0:
            right.append(len(heights))
        else:
            right.append(stack[-1][1])
    stack.append([heights[i],i])
right.reverse()
#print(right)
maxArea=0
for i in range(len(heights)):
    area=heights[i]*(right[i]-left[i]-1)
    maxArea=max(maxArea,area)
print(maxArea)
