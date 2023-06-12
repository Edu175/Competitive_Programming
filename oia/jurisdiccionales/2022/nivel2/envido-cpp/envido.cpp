#include <bits/stdc++.h>

using namespace std;

int envido(int x, string &palo1, int y, string &palo2, int z, string &palo3) {
   if(x>=10)x=0;
   if(y>=10)y=0;
   if(z>=10)z=0;
   int envido1=0,envido2=0,envido3=0;
   if(palo1==palo2)envido1=x+y+20;
   if(palo1==palo3)envido2=x+z+20;
   if(palo2==palo3)envido3=y+z+20;
  return max({x,y,z,envido1,envido2,envido3});
}
