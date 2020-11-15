def bin_search(A, left, right, k):
    while(left<=right):
        mid=(left+right)//2
        if A[mid]==k:
            return mid
        elif A[mid]>k:
            right=mid-1
        else:
            left=mid+1
    return -1        

n=int(input())
arr=list(map(int, input().strip().split(' ')))
x=int(input())
print (bin_search(arr, 0, n-1, x))