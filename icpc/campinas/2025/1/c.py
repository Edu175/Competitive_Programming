# esta mal, no es un arbol

from math import gcd
def lcm(a,b):
	return a*b//gcd(a,b)
n=int(input())
a=[]
for i in range(n):
	b=list(map(int,input().strip().split()))[1:]
	for i in range(len(b)): b[i]-=1
	a.append(b)

dp=[0 for i in range(n)]
k=1
for i in range(n):
	# print(a[i])
	if(len(a[i])):
		k*=len(a[i])
# print(k)
dp[0]=k
g=0
for i in range(0,n):
	for j in a[i]:
		dp[j]+=dp[i]//len(a[i])
	g=gcd(g,dp[i])
# print(dp)
# print(g)
print(k//g)