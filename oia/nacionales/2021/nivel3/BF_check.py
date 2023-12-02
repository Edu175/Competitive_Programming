from random import randint,choices
from os import system
import sys

it=10000
for _ in range(it):
	system("./c<pre>in")       #./c = generator
	system("./a<in>o")     #./a = solution
	system("./b<in>o2")    #./b = brute force
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	ans1=open("in","r").read()
	ans2=ans1
	for i in range(1,len(x)): ans1+=x[i]+' '
	for i in range(1,len(y)): ans2+=y[i]+' '
	open("out","w").write(ans1)
	system("./ch<out>ver")
	if(open("ver","r").read()!="Yes"):
		print("invalid solution")
		exit(0)
	open("out","w").write(ans2)
	system("./ch<out>ver")
	if(open("ver","r").read()!="Yes"):
		print("invalid bf solution??")
		exit(0)
	if (x[0]!=y[0]):
		print("FAILED!!!!!")
		print("expected",y[0],"found",x[0])
		exit(0)
	print("ok",_+1)
