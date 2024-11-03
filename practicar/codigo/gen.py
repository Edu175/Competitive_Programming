from os import system as sys
inp=open('in','w')
n=10**5
s=str(n)+"\n"
for i in range(1,n+1):
	s+="1 "+str(i)+"\n"
inp.write(s)