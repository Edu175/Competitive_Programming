def isp(x):
	i=2
	while(i*i<=x):
		if(not (x%i)): return False
		i+=1
	return True

n=int(2e5)
from math import*
r=0
for i in range(2,n):
	if(isp(i)): r+=n/i
	
print(r*log2(i))