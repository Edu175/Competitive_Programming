n,m=input().split()
n=int(n)
m=int(m)
st=set()
a=[[0]*m]*n
for i in range(n):
	for j in range(m):
		st.add(int((i+1)**(j+1)))
		a[i][j]=(i+1)**(j+1)
	#print(a[i])
print(len(st))
