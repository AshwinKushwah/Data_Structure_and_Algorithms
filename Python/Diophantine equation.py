import math

def gcd(a, b):
	if b==0:
		return a, 1, 0
	d, x1, y1=gcd(b, a%b)
	x=y1
	y=x1-y1*(a//b)
	return d, x, y
	
def find_initial_solution(a, b, c):
	g, x0, y0=gcd(a, b)
	if c%g:
		return g, 0, 0
	x0*=c//g
	y0*=c//g
	return g, x0, y0

t=int(input())
while (t):
	a, b, c=map(int, input().split())
	g, x0, y0=find_initial_solution(a, b, c)
	print("Initial", x0, y0)
	k=math.ceil((-x0*g)/b)
	x0c=x0+k*(b//g)
	y0c=y0-k*(a//g)
	k=math.floor((-x0*g)/b)
	x0f=x0+k*(b//g)
	y0f=y0-k*(a//g)
	if (abs(x0c)+abs(y0c)>abs(x0f)+abs(y0f)):
		print("minimum", x0f, y0f)
	else:
		print("minimum", x0c, y0c)
	t-=1
