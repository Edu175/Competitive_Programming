n=int(input())
ed=[]
de=[]
for i in range(n):
	s=input()
	for j in range(i):
		if s[j]=='1':
			ed.append((i,j))
		else:
			de.append((i,j))
ban=[7,2,5,9]
for (i,j) in ed:
	if not i in ban and not j in ban:
		print(i,j)
