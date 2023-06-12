from math import *
from math import factorial as f
def nCr(n,k):
	return f(n)//(f(k)*f(n-k))
n=int(input())
res=0
for i in range(1,n+1):
	res+=min((n-i+1),2**i)*(i+1)//2
print(res)
