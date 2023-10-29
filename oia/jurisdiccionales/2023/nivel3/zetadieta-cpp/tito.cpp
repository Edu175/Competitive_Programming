#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

long long zetadieta(int C, int P, int G) {
    long long A;
 if (P%30==0){
  A=P/30;
 }
 else {
    A=P/30+1;
 }
long long B;
  if (C%27==0){
  B=C/27;
 }
 else {
    B=C/27+1;
 }
double Q=G*9+A*120+B*105;
 return Q;
}
