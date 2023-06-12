from math import *
from math import factorial as f
def nCr(m,k):
	return f(m)//(f(k)*f(m-k))
def calc(n,m):
	res=0
	k=0
	while(n>=m*k):
		res+=nCr(k+n-m*k,k)
		print(k,":",k+n-m*k,k)
		k+=1
	return res
print(calc(3,2))
