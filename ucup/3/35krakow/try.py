# from random import randint
# a=randint(1,10**12)
# b=randint(1,10**12)
# st=set()
# while (a,b) not in st:
# 	print(a,b)
# 	st.add((a,b))
# 	if a<b:
# 			b-=a
# 			a+=a
# 	else:
# 			a-=b
# 			b+=b
# print(a,b)
# print(len(st))


from math import *
from fractions import Fraction as fr
def fc(n):
	if(n<0): return 0
	return factorial(n)
def cb(n,k):
	if n<0: return 0
	if k<0: return 0
	return comb(n,k)
def bruta(n):
	res=fr(0)
	for k in range(n):
		resi=fr(0)
		for x in range(n):
			term=fr(1,n)*fr(cb(n-x,k-x),cb(n,k))
			print('term x',x,term)
			resi+=term
		print('brut:',k,resi)
		res+=resi
	print('brut tot',res)
	return n+1-res

def f(n):
	res=fr(0)
	for x in range(n):
		sum2=fr(0)
		for k in range(x,n):
			sum2+=fr(fc(k))/fr(fc(k-x))
		coef=fc(n-x)
		res+=coef*sum2
		print(x,sum2*coef)
	return n+1-fr(res)/fr(n*fc(n))

print(bruta(2))
print(f(2))