n=int(input())
a=list(map(int,input().strip().split()))
b=list(map(int,input().strip().split()))
MAXN=100005
D=50
dp=[[0 for j in range(D)] for i in range(n+5)]
for d in range(D):
	dp[n][d]=0
for i in range(n-1,-1,-1):
	for d in range(D):
		dp[i][d]=(b[i]<<d)+dp[i+1][d]
		if(d<D-1):
			dp[i][d]=min(dp[i][d],(a[i]<<d)+dp[i+1][d+1])
print(dp[0][0])

