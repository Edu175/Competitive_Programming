from math import *
def p(n,k):
	q=2**(n-k)
	N=2**n
	yes=1/q
	res=(1-yes)**(q-1)*yes
	return res
n=16
k=13
print(p(n,k),'1 en',1/p(n,k))