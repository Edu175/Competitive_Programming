from os import system as sys
from random import *
it=10000
N=int(input())
for _ in range(it):
	s=""
	B=randint(2,N)
	n=1<<B
	s+=str(B)+"\n"
	a=[i for i in range(n)]
	shuffle(a)
	for i in range(n):
		if(i%2==0):
			s+=str(a[i])+' '+str(a[i+1])+'\n'
	arch=open('in','w')
	arch.write(s)
	arch.close()
	sys("./b<in>o")
	x=open('o','r').read().strip().split()
	if x[0]=='NIE':
		print("FAILED!!")
		exit(0)
	print("ok",_+1)