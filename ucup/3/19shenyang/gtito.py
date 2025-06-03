from math import *
import sys
from fractions import Fraction as fr
def ask(p,q):
	print("?",p,q)
	sys.stdout.flush()
	x=input().split()
	return fr(fr(x[0])/fr(x[1]))

t=int(input())
for i in range(t):
	n=int(input())
	p=[]
	for j in range(n):
		pi=input().split()
		p.append([fr(v) for v in pi])
	p.sort()
	A=fr(0)
	d1=fr(0)
	d2=fr(0)
	for j in range(1,n-1):
		if(p[j][0]!=p[j-1][0]): d2=ask(p[j][0],1)
		else:
			np=fr(p[j][0])+fr(1)/fr(1000)
			d3=ask(np.numerator,np.denominator)
			d4=d1-d3
			d2=int((d4.numerator+((d4.denominator+1)//2))//(d4.denominator))
		if(p[j][0]!=p[j-1][0]): 
			d2=ask(p[j][0],1)
			A=A+((d1+d2)/fr(2))*(fr(p[j][0])-fr(p[j-1][0]))
		d1=d2
		d2=0
	A=A+((d1+d2)/fr(2))*(fr(p[n-1][0])-fr(p[n-2][0]))
	print("!",A.numerator,A.denominator)
	sys.stdout.flush()
		

