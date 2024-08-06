from math import *


def fn(n):
	return n*(n+1)//2


def val(l,r):
	return fn(r)-fn(l-1)


def good(q,k,b):
	return q*k<=100-b and fn(q*k)<val(100-q+1,100)


def last(b,k):
	for i in range(1,b+1):
		if not good(i,k,b): return i-1


def prox(b):
	return last(b,100//b)
MAXX=18
N=100
W=200
mks=[0 for i in range(MAXX)]
u=0
for i in range(N):
	for j in range(i+1,N):
		a=[k for k in range(1,N+1) if i+1!=k and j+1!=k]
		u|=1<<(i*N+j)
		for x in range(1,MAXX):
			b=102
			c=max(0,x+1-b)
			d=max(0,x+1-(b-c))
			sa=sum(a[k] for k in range(c))
			sb=sum(a[k] for k in range(c,d))
			if sa<j+1 and not sb<i+1:
				mks[x]|=1<<(i*N+j)
				# print(i,j,x)
def ppc(mk):
	return bin(mk)[2:].count('1')
best=[]
# print(bin(u))
for mk in range(1<<MAXX):
	vis=0
	for x in range(MAXX):
		if (mk>>x)&1:
			vis|=mks[x]
	# print(mk,bin(vis))
	# if mk==1023:
	# 	for i in range(N):
	# 		for j in range(N):
	# 			if (vis>>(i*N+j)&1) != (u>>(i*N+j)&1):
	# 				print('differ',i,j)
	if vis==u:
		# print("pingo")
		if len(best)==0 or ppc(mk)<ppc(best[0]):
			best=[mk]
		elif ppc(mk)==ppc(best[0]):
			best.append(mk)	
# print(bin(u))
print(best)
print([bin(i) for i in best])
print([i for i in range(N) if best[0]>>i&1])