n=int(input())
a=[]
for i in range(n):
	b=list(map(int,input().strip().split()))
	b=b[1:]
	b=b[::-1]
	a.append(b)
# print(a)
INF=1<<128
ans=[]
def f(a,d):
	res=INF
	pa=[]
	for i in range(n):
		if not len(a[i]): continue
		ai=a.copy()
		resi=ai[i][0]*365**d
		ai[i]=ai[i][1:]
		c=f(ai,d+1)
		resi+=c
		if(resi<res):
			res=resi
	if(res==INF): res=0
	# print(a,d,':',pa,res)
	return res
mod=int(1e9+7)
print(f(a,1)%mod)