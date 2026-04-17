from os import system as sys
it=10000
ans=[]
best=0
for _ in range(it):
	sys('./c<pre>input')
	sys('./a<input>o')
	am=open('o','r').read().strip().split()
	assert len(am)==1
	am=int(am[0])
	a=open('input','r').read()
	print(_+1,'found',am)
	if not len(ans) or am>best:
		best=am
		ans=a
		print('new best!!',a)
print('best',best,':',ans)
	