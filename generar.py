from os import system
from os import getcwd
from os import chdir
from time import sleep
template=open('template.cpp','r').read()
d=getcwd()
pag=input('Pagina: ')
d+='/'+pag
chdir(d)
#system('cd '+pag)
con=input('Contest: ')
system('mkdir '+con)
d+='/'+con
chdir(d)
#system('cd '+con)
fin=input("Hasta (minuscula): ")
system('code ~/Desktop/padalustro.cpp')
system('code ~/Desktop/crotolamo.cpp')
for i in range(ord('a'),ord(fin)+1):
	open(chr(i)+'.cpp','w').write(template)
	system('code '+chr(i)+'.cpp')
	sleep(0.001)
# system('code {A..'+fin+'}.cpp')
system('code in')
print('cd '+pag+'/'+con)
print('python3\nfrom math import *')
#gnome-terminal --tab
