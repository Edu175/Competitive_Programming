from random import randint,choices
from os import system
import sys

it=10000
for _ in range(it):
	system("./c<pre>in")   #./c = generator
	system("./e<in>o")     #./a = solution
	system("./b<in>o2")    #./b = brute force
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	
	for i in range(len(x)):
		#flag=x[i]
		#if(flag==-1): flag=(flag==y[i])
		#if (not flag):
		if(x[i]!=y[i]):
			print("FAILED!!!!!",i+1)
			exit(0)
	print("ok",_+1)
