dat=open('in','r').read().strip().split()

x=open('o','r').read().strip().split()
y=open('o2','r').read().strip().split()

assert len(x) == len(y)
fail=-1
for i in range(len(x)):
	if x[i]!=y[i]:
		fail=i
		break
if fail==-1:
	print('ok')
	exit(0)
po=0
def readInt():
	global po
	ret=int(dat[po])
	po+=1
	return ret

t=readInt()
print(t,'testcases')
print('failed on',fail+1)
for _ in range(fail+1):
	a=readInt()
	b=readInt()
	m=readInt()
	h=[]
	for __ in range(m):
		ty=readInt()
		l=readInt()
		r=readInt()
		h.append((ty,l,r))
	print('passed',_+1)
	if(_==fail):
		print('failed test:')
		print(1)
		print(a,b,m)
		for (ty,l,r) in h:
			print(ty,l,r)
