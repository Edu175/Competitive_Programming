from os import system as sys
for i in range (1,101):
	x=open('ins/in'+str(i),'w')
	x.write("1 "+str(i))
	x.close()
	print("time ./a<ins/in"+str(i)+"\n")	