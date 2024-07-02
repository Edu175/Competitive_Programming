import sys
 
sys.stdin = open('input.txt','r')
sys.stdout = open('output.txt','w')
 
n=int(input())
if ((n%2)==0):
	print(2**(2*n//3-1)+ 2**(n//3-1) - 1)
else: 
	print(2**(2*n//3-1) + 2**(n//3) -2)