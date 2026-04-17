from fractions import Fraction as fr
n,k,l=list(map(int,input().strip().split()))
dp=[[fr(0) for j in range(n+3)] for i in range(n+3)]
n=2*n
for i in range(n-1,-1,-1):
	# print(i,'i') 
	for c in range(0,n+1):
		cant=n-i-c
		if(cant%2 or c>i): continue
		assert(cant%2==0)
		m=n-i
		c0=c
		c1=m-c
		p0=fr(c0,m); p1=1-p0
		res=0
		go0=0; go1=0
		if(p0):
			go0=fr((c>=k)+dp[i+1][c-1],2)
		if(p1):
			go1=fr((c>=k)+dp[i+1][c+1],2)
		dp[i][c]=(p0*go0)+(p1*go1)
		print(i,c,':',p0,',',p1,':',go0,',',go1,':',dp[i][c])
res=dp[0][0]
print(res)
res*=l*2**(n/2) # aca
print(res)
