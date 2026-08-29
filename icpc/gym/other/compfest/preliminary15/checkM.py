from fractions import Fraction as fr
n=int(input())
p=list(map(int,input().strip().split()))
for i in range(len(p)):
	p[i]=fr(p[i],100)
print(p)
f=[fr(0)]*(n+1)
f[0]=0
for i in range(0,n):
	f[i+1]=(f[i]-1)/(1-p[i])
	for j in range(i):
		f[i+1]-=p[i]**(j+1)*f[i-j]
print(f)
u=f[n]
ans=-u
print(ans)