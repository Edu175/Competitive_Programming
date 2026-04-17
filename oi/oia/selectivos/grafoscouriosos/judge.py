from os import system
def f(x):
	if x==10: return str(x)
	else: return "0"+str(x)
score=0
for test in range (1,11):
	#print(test,f(test))
	inp="casos-grafos-curiosos/grafoscuriosos"+f(test)+".txt"
	#a=open(inp,"r").read().strip().split()[1:]
	system("./a<"+inp+">o")
	system("./d<o>r")
	ans=open("r","r").read().strip()
	print("Test "+str(test)+":\n"+ans)
	if ans.split()[0]=="OK":
		print("10 points")
		score+=10
	else:
		print("0 points")
	print('\n')
print("Final score:",score)
