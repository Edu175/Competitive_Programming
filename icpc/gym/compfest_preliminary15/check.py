from os import system as sys

it = 100000

for _ in range (it):
	sys("./c>in.txt")
	sys("./b<in.txt>out.txt")
	sys("./a<in.txt>out2.txt")
	x = open("out.txt","r").read().strip().split()
	y = open("out2.txt","r").read().strip().split()
	if(x!=y):
		print("FAILED")
		exit(0)
	print(":D",_+1)
	