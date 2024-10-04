n=int(input())
def g1(n):
	a=[0 for i in range(3*n)]
	res=[]
	for i in range(1,n):
		if not a[i]:
			a[i]=a[2*i]=a[3*i]=1
			res.append(i)
	print(len(res),': ',res)
	
def g2(n):
	a=[0 for i in range(3*n)]
	res=[]
	for i in range(1,n):
		c=0
		for j in range(1,4):
			c+=i*j<n and not a[i*j]
		if c>=2 or not a[i]:
			a[i]=a[2*i]=a[3*i]=1
			res.append(i)
	# print(len(res),': ',res)
	print(len(res))
	
g1(n)
g2(n)
