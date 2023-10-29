from os import system

name=input("nombre:")
key=input("keyword:")
system("grep -r \""+key+"\" > files")
x=open("files","r").read().strip().split()
system("mkdir "+name)
com="sudo mv -t "+name+"/ "
for i in range(len(x)):
	if(x[i][0]!="f" or not "." in x[i]):
		continue
	s=t=""
	p=0
	j=0
	while(j<len(x[i]) and x[i][j]!=':'):
		t+=x[i][j]
		j+=1
	com+=t
	com+=" "
system(com)
