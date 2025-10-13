from math import *
from builtins import *
rt=884618610
# rt=115381398
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
	if len(e) == h:
		one=0
		for ex in range(3):
			prod=1
			for i in range(h):
				sum=0
				for t in range(k+1):
					cur=mul(rts[e[i]],rts[ex])
					cur=pow(cur,t,MOD)
					sum=add(sum,cur)
				prod=mul(prod,sum)
			one=add(one,prod)
		one=pow(one,w,MOD)
		res=add(res,one)
		return
	for v in range(3):
		e.append(v)
		f()
		e.pop()
f()
print(res)
res=mul(res,pow(3,-(h+w),MOD))
print(res)

