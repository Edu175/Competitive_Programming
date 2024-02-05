from math import *
t=int(input())
for _ in range(t):
	n=int(input())
	res=list()
	for i in range(0,n):
		for j in range(0,n):
			for k in range(0,n):
				if(i<n-1 and j<n-1 and k<n-1):
					continue;
				if(i==j or i==k or j==k):
					continue;
				x=10**i+6*10**j+9*10**k
				if(floor(sqrt(x))*floor(sqrt(x))==x):
					res.append(x)
	print(len(res))
	for i in range(n):
		print(res[i])
