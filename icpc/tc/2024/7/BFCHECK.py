from random import randint,choices
from os import system
import sys
it=10000
for _ in range(it):
	system("./c>in")
	system("./a<in>o")
	system("./b<in>o2")
	x=open("o","r").read().strip().split()
	y=open("02","r").read().strip().split()
	
	for i in range(len(x)):
		if(x[i]!=y[i]):
			print("FAILDE!!",i+1)
			print("expected",y[i],"found",x[i])
			exit(0)
	print("ok",_+1)