t=int(input())
for _ in range(t):
	n,d=list(map(int,input().strip().split()))
	pot=1
	s=0
	while pot<n:
		pot*=(d+1)
		s+=1
	print(s)