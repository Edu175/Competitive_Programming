from os import system
for p in range(1,11):
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
	
	for i in range(n):
		for j in range(i+1,n):
			if s[i+1][j]=='1':
				a.append((i,j))
	g+=str(n)+' '+str(len(a))+'\n'*2
	for (i,j) in a:
		g+=str(i+1)+' '+str(j+1)+'\n'
	open('in','w').write(g)
	system('g++ -std=c++17 tc'+str(p)+'.cpp -o a&&./a<in>o')
	if open('o','r').read()[0]!='1':
		print('FAILED!!!')
		exit(0)
	print('ok',p)
