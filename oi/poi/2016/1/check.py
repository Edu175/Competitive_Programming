from os import system as sys
from random import *
it=10000
for _ in range(it):
	sys("./c<pre>in")
	sys("./a<in>o")
	sys('./b<in>o2')
	x=open('o','r').read().strip().split()
	y=open('o2','r').read().strip().split()
	if x!=y:
		print("FAILED!!")
		print('expected',y)
		print('found',x)
		exit(0)
	print("ok",_+1)