I=input
R=range
n,k=map(int,I().split())
a=I().split()*2

m=2*n
s=p=0
F=[[0]*m]
for i in R(m):
	while p<m and s<=k:
		s+=int(a[p])
		p+=1
	F[0][i]=p-1
	s-=int(a[i])
for k in R(18):
	f=F[k]
	F+=[[f[f[i]] for i in R(m)]]

for i in R(n):
	r=1
	x=i
	for k in R(18,-1,-1):
		v=F[k][x]
		if v<i+n:
			x=v
			r+=1<<k
	p=min(p,r)
print(p)

