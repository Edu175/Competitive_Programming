n=int(input())
a=list(map(int,input().strip().split()))
a.sort()
a=a[::-1]
# print(a)
mx=0
tot=sum(a)
s=0
for i in range(n):
	s+=a[i]
	cur=s*n-(i+1)*tot
	# print(i,cur)
	mx=max(mx,cur)
# print(mx)
# print(n,tot)

res=mx*100/(n*tot)
print(f"{res:.15f}")