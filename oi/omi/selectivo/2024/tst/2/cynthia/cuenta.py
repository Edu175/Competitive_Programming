from math import *
n=int(input())
res=0
for i in range(n):
	res+=1<<gcd(i,n)
res/=n
print(res)