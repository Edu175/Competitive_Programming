from math import comb
INF=10**60+100
MAXS=61
MAXD=1000
dp=[[0]*MAXS for i in range(MAXD)]
# dp[0]=[1]*MAXS
for i in range(MAXS): dp[0][i]=1
for d in range(1,MAXD):
	for s in range(MAXS):
		for c in range(0,s+1):
			dp[d][s]+=dp[d-1][c]*comb(s,c)
			dp[d][s]=min(dp[d][s],INF)
	print('d=',d,dp[d])