def partition(arr,low,high):
    pivot=high
    i=low-1
    for j in range(low,high):
        if arr[j]<arr[pivot]:
            i+=1
            arr[i],arr[j]=arr[j],arr[i]
    i+=1        
    arr[i],arr[pivot]=arr[pivot],arr[i]  
    return i
        

def quickSort(arr,low,high):
    if low < high:
        pi = partition(arr,low,high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)


if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int,input().split()))
        quickSort(arr,0,n-1)
        for i in range(n):
            print(arr[i],end=" ")
        print()