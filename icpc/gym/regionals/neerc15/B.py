MAXL=200

#define cf __builtin_ctzll
def cf(x):
	res=0
	if x==0: return MAXL+5
	while not (x&1):
		res+=1
		x>>=1
	return res
# freopen("binary.in","r",stdin);
# freopen("binary.out","w",stdout);
import sys
sys.stdin = open('binary.in', 'r') 
sys.stdout = open('binary.out', 'w')

pot10=[0]*MAXL
pot5=[0]*MAXL
pot10[0]=1
pot5[0]=1
for i in range(1,len(pot10)): pot10[i]=pot10[i-1]*10
for i in range(1,len(pot5)): pot5[i]=pot5[i-1]*5

k=int(input())
k-=1
_k=k
a=[[(0,0)],[(1,0)]]
# vector<vector<ii>> a(2);
for L in range(2,MAXL):
		if(k<len(a[1])):
			print(a[1][k][0])
			exit(0)
		k-=len(a[1])
		prox=[[],[]]
		idx=L-1
		for w in range(0,2):
			for (v,s) in a[w]:
				if(cf(s)>=L):
					prox[0].append((v,s))
					v+=pot10[idx]
					s+=(pot5[idx]-1)<<idx
					prox[1].append((v,s))
		a=[]
		for i in prox: a.append(i)
print(_k-k,"pasaron")
assert(0)