MAXN=76
dp0=[[0 for j in range(MAXN)] for i in range(MAXN)]
dp1=[[0 for j in range(MAXN)] for i in range(MAXN)]
for c in range(74):
	dp0[75][c]=dp1[75][c]=0
	dp0[74][c]=dp1[74][c]=1
for h in range(74):
	dp0[h][75]=dp1[h][75]=1
	dp0[h][74]=dp1[h][74]=0
wh=[[[0 for k in range(MAXN)] for j in range(MAXN)] for i in range(MAXN)]
for h in range(73,-1,-1):
	for c in range(73,-1,-1):
		def doit(m): # assigns dp[h][c] and wh
			cur0=[0]*(MAXN+10)
			cur1=[0]*(MAXN+10)
			cur0[0]=m
			dp0[h][c]=m
			for t in range(MAXN-1,-1,-1):
				if(c+t>75):
					cur1[t]=cur0[0]
					continue
				res=dp0[h][c+t]
				roll=cur0[0]; # 1
				for i in range(2,7): roll+=cur1[t+i]
				roll/=6
				wh[h][c][t]=roll>res
				res=max(res,roll)
				cur1[t]=res
			
			dp1[h][c]=cur1[0]
			
			for t in range(MAXN-1,-1,-1):
				if(h+t>75):
					cur0[t]=cur0[0]
					continue
				res=dp1[h+t][c]
				roll=cur1[0] # 1
				for i in range(2,7): roll+=cur0[t+i]
				roll/=6
				res=min(res,roll)
				cur0[t]=res
			dp0[h][c]=cur0[0]
	
		l=0;r=1
		for _ in range(100):
			m=(l+r)/2
			doit(m)
			if(m<=dp0[h][c]): l=m
			else: r=m
		m=r
		doit(m)

q=int(input())
for _ in range(q):
	c,h,t=list(map(int,input().strip().split()))
	print("HC"[wh[h][c][t]])