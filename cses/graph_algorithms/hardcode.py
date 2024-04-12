from os import system
res=[["" for j in range(8)] for i in range(8)]
for i in range(8):
	for j in range(8):
		a=open("input","w")
		a.write(str(i+1)+" "+str(j+1))
		a.close()
		system("./a<input>out")
		x=open("out","r").read().strip().split()
		#print(x,'|',len(x))
		s=""
		for i_ in range(8):
			for j_ in range(8):
				s+=x[i_*8+j_]+' '
			s+='\\n'
		#print(i,j,'|',s)
		res[i][j]=s
a=open("tests","w")
a.write("")
a.close()
a=open("tests","a")
def dfs(l,r,i,s,d):
	m=(l+r)//2
	if r-l==1:
		if(s=='x'):
			dfs(1,9,l,'y',d)
		else: 
			a.write("\t"*d+"cout<<\""+res[i-1][l-1]+"\";\n")
			a.write("\t"*d+"exit(0);\n")
		return
	a.write("\t"*d+"if("+s+"<\'"+str(m)+"\'){\n")
	dfs(l,m,i,s,d+1)
	a.write("\t"*d+"}\n")
	a.write("\t"*d+"else {\n")
	dfs(m,r,i,s,d+1)
	a.write("\t"*d+"}\n")
#print(res)
dfs(1,9,0,'x',0)
a.close()
