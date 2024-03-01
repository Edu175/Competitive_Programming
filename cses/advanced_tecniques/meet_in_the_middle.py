from collections import *
n,k,*a = map(int, open(0).read().split())
def f(a):
	d=[0]
	for i in a:
		d+=[i+j for j in d]
	return d
n//=2
d=Counter(f(a[:n]))
print(sum(d[k-i] for i in f(a[n:])))
