from os import system as sys
it = 100000
for _ in range(it):
	sys("./c<pre>in")
	sys("./a<in>o")
	x = open("o","r").read().strip().split()
	if( len(x) == 0):
		print("FAILED!!!!")
		exit(0)
	print("ok",_+1)