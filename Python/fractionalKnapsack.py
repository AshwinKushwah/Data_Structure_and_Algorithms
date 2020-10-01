"""" fractional knapsack problem"""
(n,W)=input().split()
number=int(n)
Wmax=int(W)
weights=list()
values=list()
ratio=list()

for i in range(number):
    (v,w)=input().split()
    values.append(int(v))
    weights.append(int(w))
    ratio.append(values[i]/weights[i])
tbl=list()

for i in range(number):
    lst=list()
    lst.append(ratio[i])
    lst.append(i)
    tbl.append(lst)

tbl.sort(reverse=True)
currentWeight=0
i=0
currentValue=0
while currentWeight<=Wmax and i<=number-1:
    k=min(Wmax-currentWeight,weights[tbl[i][1]])
    currentWeight+=k
    currentValue+=k*tbl[i][0]
    i+=1
print(float(currentValue))
