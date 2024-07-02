from os import system

def f(x):
	return "0"*(2-len(str(x)))+str(x)

#for i in range (1,11):
#	system("./a < "+f(i+1)+" > nowruz"+str(i)+".out.txt")
for i in range(1,11):
	system("cp  nowruz"+str(i)+".out.txt "+f(i+1)+".out")