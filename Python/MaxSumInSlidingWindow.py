import math
# this algorithm calculates the maximum sum present in the sublists of length k
# in the array
nums=list(map(int,input("enter the elements of the list\n").split()))
k=int(input("enter the size of the window :"))
cursum=sum(nums[:k])
maxsum= cursum
for i in range(1,len(nums)-k):
    cursum=cursum-nums[i-1]+nums[i+k-1]
    maxsum=max(cursum,maxsum)
print(maxsum)

print('assertion:---  ',end=" ")
print(maxsum==maxsumink(nums,k))

