from math import gcd
n=int(input())
a=list(map(int,input().strip().split()))
for i in range(n): a[i]-=1
vis=[0 for i in range(n)]
g=1
for x in range(n):
	if not vis[x]:
		z=0
		y=x
		while not vis[y]:
			z+=1
			vis[y]=1
			y=a[y]
		g=g*z//gcd(g,z)
print(g%(10**9+7))
		