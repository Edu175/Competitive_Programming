from os import system
import sys

it=100
_=0
#for _ in range(it):
while(it):
	_+=1
	system("./c>in")       #./c = generator
	system("./a<in>o")     #./a = solution
	system("./b<in>o2")    #./b = brute force
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	
	for i in range(len(x)):
		if (x[i]!=y[i]):
			print("FAILED!!!!!",i+1)
			print("expected",y[i],"found",x[i])
			exit(0)
	print("ok",_)
