from os import system
from random import shuffle
import sys
def code(p):
	print('caso ',p)
	t="subredes"+"0"*(2-len(str(p)))+str(p)+".in"
	s=open(t,'r').read().strip().split()
	n=int(s[0])
	s=s[:n+1]
	a=[]
	g=''
	for i in s:
		g+=i+'\n'
	g+='\n1\n'
	per=[i for i in range(n)]
	shuffle(per)
	print('hidden permutation:',per)
	for i in range(n):
		for j in range(0,i):
			if s[i+1][j]=='1':
				a.append((per[i],per[j]))
	g+=str(n)+' '+str(len(a))+'\n'*2
	for (i,j) in a:
		g+=str(i+1)+' '+str(j+1)+'\n'
	open('in','w').write(g)
	system('g++ -std=c++17 tc'+str(p)+'.cpp -o a&&./a<in>o')
	if open('o','r').read()[0]!='1':
		print('FAILED!!!')
		exit(0)
	print('ok',p)
#print(sys.argv)
if len(sys.argv)>1:
	code(sys.argv[1])
else:
	for p in range(1,11):
		code(p)
