import matplotlib.pyplot as plt
X=[]
for i in range(21):
	s=input()
	a=[]
	for i in s:
		a.append(i=='1')
	X.append(a);
print(X)
im = plt.imshow(X, cmap='Greys')
plt.show()
