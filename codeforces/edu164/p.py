'''for i in range(1<<5):
	if(1<=bin(i).count('1')<=2):
		s=bin(i)[2:]
		s='0'*(5-len(s))+s
		print(s)'''
def query(n,c,k):
	res=0
	for mk in range(1<<n):
		q=0
		mx=0
		for i in range(2*n):
			if (mk>>(i%n))&1:
				q+=1
			else:
				mx=max(mx,q)
				q=0
		if(mk==(1<<n)-1):
			mx=n
		if(bin(mk).count('1')<=k and mx>=c):
			res+=1
	return res
