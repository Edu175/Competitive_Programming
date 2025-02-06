from time import *
from random import *
from math import *
def ones(n):
	n+=1
	res=0
	ni=n
	a=list()
	while(ni):
		a.append(ni%10)
		ni//=10
	#print(a)
	for i in range(len(a)):
		if(i): res+=10**(i-1)*i*a[i]
		if(a[i]>1): res+=10**i
		if(a[i]==1): res+=n%10**i
	return res
def dig(n):
	res=0
	while(n):
		res+=1
		n//=10
	return res
k=int(input())
def value(a):
	return k*a-ones(a)

def vecino(a,r):
	d=randint(0,dig(r))
	x=(int(a)//10**d)%10
	return min(r,a-x*10**d+randint(0,9)*10**d)
def random_state(r):
	return randint(1,r)
eps=1e-7
def P(old,now,t):
	if(now<old): return 1.0
	return exp((old-now)/t)
def simulated_annealing(r):
	start=process_time()
	s=random_state(r)
	best=s
	t=1e5
	while(t>=eps):#process_time()-start<=1.99):
		now=vecino(s,r)
		if(value(s)<value(best)): best=s
		if(value(best)<0): return best
		if(P(s,now,t)>=random()): s=now
		t*=0.99999
	#print('t',t)
	return best
#ret=simulated_annealing()
#print(ret,value(ret))
l=1; r=10**(10*k+1)
it=10**6
while(l<=r):
	print(l,r)
	if(r-l<=it): break
	m=(l+r)//2
	if(value(simulated_annealing(m))<0): r=m-1
	else: l=m+1
for i in range(l,r+1):
	mini=value(simulated_annealing(m))
	if(mini<0):
		print(i,mini)
		break
