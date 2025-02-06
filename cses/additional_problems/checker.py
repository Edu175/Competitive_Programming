a=open('in','r').read().strip().split()[1:]
n=len(a)
a=[int(i) for i in a]
x=open('o','r').read().strip().split()
# print(x)
if x[0]=='IMPOSSIBLE':
	print('AC')
	exit(0)
x=[int(i) for i in x]
s=[[],[]]
mex=1
def fail():
	print('WA')
	exit(0)
def cum(w):
	global mex
	if len(s[w]) and s[w][-1]==mex:
		s[w].pop()
		mex+=1
		return 1
	return 0

for i in range(n):
	while cum(0) or cum(1): assert(1)
	to=x[i]
	to-=1
	v=a[i]
	if len(s[to]) and s[to][-1]<v: fail()
	s[to].append(v)
print('AC')