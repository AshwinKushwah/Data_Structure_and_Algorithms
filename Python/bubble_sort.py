def bubbleSort(lst):
    for no in range(len(lst)-1,0,-1):
        for i in range(no):
            if lst[i]>lst[i+1]:
                temp = lst[i]
                lst[i] = lst[i+1]
                lst[i+1] = temp
     return lst
     
lst = list()
num = raw_input("Enter how many elements you want:")
print 'Enter numbers in array: '
for i in range(int(num)):
    n = input("num :")
    lst.append(int(n))

print(bubbleSort(lst))

