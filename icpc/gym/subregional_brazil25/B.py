from math import gcd
import sys
def merge(r1,m1,r2,m2):
	# print('merge',r1,m1,r2,m2)
	g=gcd(m1,m2)
	# if b%g: return None
	# m1//=g
	m2//=g
	# inv=pow(m1//g,-1,m2) # m1 y m2 SON coprimos
	m=m1*m2
	return (((r2-r1)//g*pow(m1//g,-1,m2)%m*m1+r1)%m,m)

data = list(map(int, sys.stdin.buffer.read().split()))
it = iter(data)
n = next(it)
a = [next(it) for _ in range(n)]
b = [next(it) for _ in range(n)]
p = [next(it)-1 for _ in range(n)]


def fail():
	print("IMPOSSIVEL")
	exit(0)

def get(a,b):  # r[i]: longest border of t[0,i)
	n=len(a)
	r=[0]*(n+1)
	r[0]=-1
	j=-1
	p=-1
	# a part
	for i in range(n):
		while j>=0 and a[i]!=a[j]:
			j=r[j]
		j+=1
		r[i+1]=j
	j=0 # -1
	# first b part
	for i in range(n):
		ac=i+n+1
		while j>=0 and (j==n or b[i]!=a[j]):
			j=r[j]
		j+=1
		if j>=n:
			if p!=-1: return (p-(n<<1),ac-p)
			p=ac
	# second b part
	for i in range(n):
		ac=i+(n<<1)+1
		while j>=0 and (j==n or b[i]!=a[j]):
			j=r[j]
		j+=1
		if j>=n:
			if p!=-1: return (p-(n<<1),ac-p)
			p=ac
	if p==-1: fail()
	return (p-(n<<1),n)

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