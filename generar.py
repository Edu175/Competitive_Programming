from os import system
from os import getcwd
from os import chdir
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
fin=input("Hasta: ")
for i in range(ord('A'),ord(fin)+1):
	open(chr(i)+'.cpp','w').write(template)
	system('gedit '+chr(i)+'.cpp')
system('gedit in')
print('cd '+pag+'/'+con)
print('python3\nfrom math import *')
#gnome-terminal --tab
