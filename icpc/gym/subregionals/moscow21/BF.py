from random import randint,choices
from os import system
import sys

it =10000
for _ in range(it):
	system("./c<pre>in")
	system("./a<in>o")
	system("./b<in>o2")
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	if(x!=y):
		print("FAILED",_+1)
		exit(0)
	print("ok", _+1)
		