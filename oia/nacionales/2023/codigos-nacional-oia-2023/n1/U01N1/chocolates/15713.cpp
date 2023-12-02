#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int chocolates(int K, vector<int> &x){
  vector<int> nuevo = x;
  bool uno = true;
  for(int i = 0; i < x.size(); i++){
    if(nuevo[i] != 1) uno = false;
  }
  if(uno){
    int suma = 0;
    for(int i = 0; i < x.size(); i++){
      suma += nuevo[i];
    }
    return (int) suma / K;
  }
  int cantidad = 0;
  if(K != 1){
    while(nuevo.size() > K - 1){
      sort(nuevo.begin(), nuevo.end());
      reverse(nuevo.begin(), nuevo.end());
      nuevo[0]--;
      nuevo[1]--;
      nuevo[2]--;
      cantidad++;
      for(int i = 0; i < nuevo.size(); i++){
        if(nuevo[i] == 0){
          nuevo.erase(nuevo.begin() + i, nuevo.begin() + i + 1);
          i -= 2;
          if(i < 0) i = 0;
        }
      }
      if(nuevo.size() < K){
        cantidad--;
        break;
      }
      if(nuevo.size() == K - 1){
        cantidad--;
        break;
      }
    }
  }
  else{
    for(int i : nuevo){
      cantidad += i;
    }
  }
  return cantidad;
}
