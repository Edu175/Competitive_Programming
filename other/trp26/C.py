from fractions import Fraction as fr
n,m=list(map(int,input().strip().split()))
a=list(map(int,input().strip().split()))
b=list(map(int,input().strip().split()))
assert len(a)==n
assert len(b)==m
numA=1
denA=1
for x in a:
	numA*=x*(x+1)//2
	denA*=x
numB=1
denB=1
for x in b:
	numB*=x*(x+1)//2
	denB*=x
dif=numA*denB-numB*denA
print('A:',numA,denA)
print('B:',numB,denB)
if dif>0: print("ALICE")
if dif<0: print("BOB")
if dif==0: print("EMPATE")
