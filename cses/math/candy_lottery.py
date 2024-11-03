def fpow(b,e):
	ret=1
	while e:
		if e&1: ret*=b
		b*=b
		e>>=1
	return ret
n,k=map(int,input().strip().split())
res=0
for i in range(1,k+1):
	res+=i*(fpow(i/k,n)-fpow((i-1)/k,n))
print(f"{round(res,6):.{6}f}")