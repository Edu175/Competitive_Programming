import matplotlib.pyplot as plt
from random import *
n=int(input())
a=list(map(int,input().strip().split()))
b=list(map(int,input().strip().split()))
c=[0 for i in range(n)]
for i in range(n):
	c[i]=a[i]-b[i]
def greedy(z,c):
	res=abs(z)
	d=[i for i in c]
	#print(z,d)
	d[0]+=z
	d[-1]-=z #safety
	for i in range(len(d)-1):
		res+=abs(d[i])
		d[i+1]+=d[i]
	#print(d)
	assert d[-1]==0
	print("greedy",z,'=',res)
	return res
def see(c):
	print(c)
	s=0
	for i in c:
		s+=abs(i)
	s//=2
	x=[]
	for i in range(-s-5,s+6):
		x.append(greedy(i,c))
	plt.plot(x)
	plt.show()
see(c)
'''
v=int(input())
d=[]
s=0
for i in range(n-1):
	d.append(randint(-v,v))
	s+=d[-1]
d.append(-s)
see(d)'''
