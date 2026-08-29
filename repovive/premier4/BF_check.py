from os import system as sys

it=10000
for _ in range(it):
	sys("./c<pre>in")	#./c = generator
	sys("./a<in>o")		#./a = solution
	x=open("o","r").read().strip().split()
	
	if not len(x):
		print("FAILED!!!!!")
		exit(0)
	
	print("ok",_+1)
