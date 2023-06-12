from random import randint,choices
from os import system
import sys

it=100
for _ in range(it):
	system("./c<pre>in")
	system("./a<in>o")
	system("./b<in>o2")
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	
	for i in range(len(y)):
		if(x[i]!=y[i]):
			print("FAILED!!!!!",_+1)
			print("expected",y[i],"found",x[i])
			exit(0)
	print("ok",_+1)
			
