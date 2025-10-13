from math import *
from builtins import *
rt=884618610
MOD=int(1e9+9)
def add(a,b):
	return (a+b)%MOD
def mul(a,b):
	return (a*b)%MOD

h,w,k=list(map(int,input().strip().split()))
e=[]
rts=[1,rt,rt**2%MOD]
res=0
def f():
	global res
	if len(e) == h+w:
		prod=1
		for j in range(w):
			for i in range(h):
				sum=0
				for t in range(k+1):
					cur=mul(rts[e[i]],rts[e[h+j]])
					cur=pow(cur,t,MOD)
					sum=add(sum,cur)
				prod=mul(prod,sum)
		res=add(res,prod)
		return
	for v in range(3):
		e.append(v)
		f()
		e.pop()
f()
print(res)
res=mul(res,pow(3,-(h+w),MOD))
print(res)

