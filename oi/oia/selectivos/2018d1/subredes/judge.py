s=0
for p in range(1,11):
	num='0'*(2-len(str(p)))+str(p)
	ans=open('testcases/subredes'+num+'.dat','r').read().strip().split()
	out=open('subredes'+num+'.out','r').read().strip().split()
	v='Test '+str(p)+': '
	if out==ans:
		v+='10 points'
		s+=10
	else:
		v+='0 points'
	print(v)
print('Total:',s,'points')
