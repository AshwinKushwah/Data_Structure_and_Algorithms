'''
Given a binary number, Find, if given binary number is a multiple of 3. 
The given number can be big upto 2^10000. 
It is recommended to finish the task using one traversal of input binary string.
'''
n=int(input())
for _ in range(n):
 s=input()
 v=int(s,2)
 if v%3==0:
  print(1)
 else:
  print(0)
