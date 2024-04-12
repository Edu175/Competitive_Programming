from math import *
from random import *
def f(n):
	res=0
	N=n
	oln=n
	while(n>2):
		res+=1
		print(n)
		oln=n
		n=sqrt(n)+randint(0,1000)
		if(n==oln): break
		
	print(n)
	return res
print(f(2316400000000000))
