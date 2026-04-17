from os import system
import sys

#print(sys.argv)
n=int(sys.argv[1])
#print(n)
nombre='subredes'+'0'*(2-len(str(n)))+str(n)
com=''
if len(sys.argv)>2:
	print('overwritten')
	com='g++ -O2 -std=c++17 -Wall -Wextra tc'+str(n)+'.cpp -o a&&time ./a<'+nombre+'.in>'+nombre+'.out&&cat '+nombre+'.out'
else:
	com='g++ -O2 -std=c++17 -Wall -Wextra tc'+str(n)+'.cpp -o a'
print(com)
system(com)
