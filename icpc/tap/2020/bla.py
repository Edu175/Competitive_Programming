n=5782344
mod=int(1e9+7)
u=n
def pm(a,b):
	r=1
	while(b):
		if(b&1): r=r*a%mod
		a=a*a%mod
		b//=2
	return r
print(pm(n,(mod-1)//2),pm(n,2))