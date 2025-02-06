from os import system as sys

it=10000
for _ in range(it):
	sys("./c<pre>in")	#./c = generator
	sys("./b<in>o")
	x=open("o","r").read().strip().split()
	
	if not len(x):
		print("FAILED!!!!!")
		print("expected",y,"found",x)
		exit(0)
	
	print("ok",_+1)
