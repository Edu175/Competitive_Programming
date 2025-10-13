from math import gcd
import sys
def merge(r1,m1,r2,m2):
	# print('merge',r1,m1,r2,m2)
	g=gcd(m1,m2)
	b=r2-r1
	# if b%g: return None
	_m1=m1
	m1//=g
	m2//=g
	b//=g
	inv=pow(m1,-1,m2) # m1 y m2 SON coprimos
	x=b*inv%m2
	# print(b,m1,m2,':',x)
	m=_m1*m2
	return ((x*_m1+r1)%m,m)

data = list(map(int, sys.stdin.buffer.read().split()))
it = iter(data)
n = next(it)
a = [next(it) for _ in range(n)]
b = [next(it) for _ in range(n)]
p = [next(it)-1 for _ in range(n)]

P=1777771
MOD=10**9+9
PI=pow(P,-1,MOD)
assert P*PI%MOD==1
pot=[0]*(n+3)
pot[0]=1
for i in range(1,len(pot)): pot[i]=pot[i-1]*P%MOD

def fail():
	print("IMPOSSIVEL")
	exit(0)

def get(a,b): # rotations to the right to get b
	ha=0
	for i in a: ha=(ha*P+i)%MOD
	hb=0
	for i in b: hb=(hb*P+i)%MOD
	r=-1
	# print(a,b)
	n=len(a)
	for i in range(2*n):
		if ha==hb:
			if r!=-1:
				# print(r,i-r)
				return (r,i-r)
			r=i
		u=a[n-1-i]
		ha=((ha-u)*PI+pot[n-1]*u)%MOD
	# print(r)
	fail()

es=[] # equations
vis=[0]*n
mr=[-1]*(n+5)
for x in range(n):
	if vis[x]: continue
	y=x
	ca=[]
	cb=[]
	while not vis[y]:
		ca.append(a[y])
		cb.append(b[y])
		vis[y]=1
		y=p[y]
	(r,m)=get(ca,cb)
	if mr[m]!=-1:
		if mr[m]!=r: fail()
	else: 
		mr[m]=r
		for (r2,m2) in es:
			if (r2-r)%gcd(m,m2): fail()
		es.append((r,m))
es.sort(key=lambda x: x[1])
r=0
m=1
L=10**9
done=0
fg=1
# print(es)
for (r2,m2) in es:
	if done:
		fg&=r%m2==r2
		continue
	# print(r,m)
	(r,m)=merge(r,m,r2,m2)
	if m>L+5: done=1
if r>L: fg=0
if fg: print(r)
else: print('DEMAIS')