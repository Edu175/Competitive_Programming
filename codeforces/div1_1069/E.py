# from sympy.ntheory.modular import crt
from math import gcd
def combine(a,b,m,n): # n,m coprime
	assert gcd(m,n)==1
	k=(b-a)*pow(m,-1,n)
	x=(m*k+a)%(m*n)
	return (x,m*n)
def crt(ms,rs): # asumo pairwise coprime
	a=0; m=1
	for i in range(len(ms)):
		b=rs[i]; n=ms[i]
		a,m=combine(a,b,m,n)
	return a,m
def ask(b):
	print('?',b)
	ret=int(input())
	if ret==-2: exit(0)
	return ret
def answer(x):
	print('!',x)
	r=int(input())
	if not r: exit(0)

def do_crt(bs,rs):
	ms=[i-1 for i in bs]
	assert(len(ms))
	mx=max(bs)
	assert mx == bs[-1]
	(sol,mod)=crt(ms,rs)
	# print(ms,rs)
	# print('=',sol,mod)
	if sol<mx: sol+=mod
	assert sol>=mx
	answer(sol)

a=[0,29,4,1596,2,8,56,46254]
n=len(a)

t,_k,_c=list(map(int,input().strip().split()))
for __ in range(t):
	k=1; bs=[]; rs=[]
	while k<n:
		b=a[k]
		got=ask(b)
		k*=2
		if got!=-1:
			bs.append(b)
			rs.append(got)
			k+=1
	if not len(bs): answer(1)
	elif len(bs)==1 and bs[0]<=4: answer(rs[0]+bs[0]-1)
	else: do_crt(bs,rs)