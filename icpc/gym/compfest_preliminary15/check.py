from os import system as sys

it = 10000

for _ in range (it):
	sys("./c<pre>in")
	sys("./b<in>out")
	sys("./a<in>out2")
	x = open("out","r").read().strip().split()
	y = open("out2","r").read().strip().split()
	if(x!=y):
		print("FAILED")
		exit(0)
	print("ok",_+1)
	