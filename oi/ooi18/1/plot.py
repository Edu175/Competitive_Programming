from matplotlib.pyplot import *
t,g=map(int,input().strip().split())
n=int(input())
for i in range(n):
	x,y=map(int,input().strip().split())
	plot(x,y,'bo',label=str(i+1))
show()
