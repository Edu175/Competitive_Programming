n,m=list(map(int,input().strip().split()))
did=0
from math import gcd
def get(a,m,d):
	g=
	if not a: a+=d
	return a
if n==2:
	for a in range(1,m+1):
		b=m-a
		if b<=a: break
		print(a*b+1,end=" ")
		did=1
else:
	for d in range(1,m+3):
		a=get(a,m,d)
		if a==-1: continue
		if n*a+n*(n-1)*d<=m and a*a%d==d-1:
			print(d,end=" ")
			did=1
	print()
if not did: print(-1)