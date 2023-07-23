import math
from os import system
import sys
MAXF=100
MAXN=100

fc=[]
def factorials():
	for i in range(MAXF):
		fc.append(0)
	fc[0]=1;
	for i in range(1,MAXF):
		fc[i]=fc[i-1]*i

def nCr(n,k):
	if(n<0 or k>n or k<0):
		return 0
	return fc[n]//(fc[n-k]*fc[k])

dp=[]

factorials();
for i in range(MAXN):
	dp.append(0)
n=int(input())
k=int(input())
dp[0]=1;
s=0;

for m in range(1,n+1):
	for i in range(k,m+1):
		dp[m]+=(fc[m-1]//fc[m-i])*dp[m-i]
		#print("(",fc[m-1],'//',fc[m-1],")*",dp[m-1])
	#if(m-k>=0):
	#	s+=dp[m-k]//fc[m-k]
	#dp[m]=fc[m-1]*s
	#print(m,dp[m])
print(int(dp[n]))
