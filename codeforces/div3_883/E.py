from os import system
import sys
from math import *

def fpow(b,e):
	ret=1
	while(e):
		if(e&1):
			ret=ret*b
		b*=b
		e/=2
	return ret

t=int(input())
while(t):
	t-=1
	n=int(input())
	flag=0
	for e in range (61):
		l=2
		r=sqrt(n)+5
		while(l<=r):
			m=(l+r)/2
			if(fpow(m,e+1)-1<=n*(m-1)):
				r=m-1
			else:
				l=m+1
		if(r>=2 and fpow(r,e+1)-1<=n*(m-1)):
			flag=1
	if(flag):
		print("YES")
	else:
		print("NO")
			
