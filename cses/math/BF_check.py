from random import randint,choices
from os import system
import sys

it=100
for _ in range(it):
	# system("./c<pre>in")
	arch=open('in','w')
	arch.write(str(_+1))
	arch.close()
	system("./a<in>o")
	system("python3 correct.py<in>o2")
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	for i in range(len(x)):
		if (x[i]!=y[i]):
			print("FAILED!!!!!",i+1)
			print("expected",y[i],"found",x[i])
			exit(0)
	print("ok",_+1)
