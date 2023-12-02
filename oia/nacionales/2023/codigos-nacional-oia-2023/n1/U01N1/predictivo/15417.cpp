#include <string>
#include <vector>
#include <iostream>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<string> pedazos = {""};
    int b = 0;
    while(b < texto.size()){
      if(texto[b] == ' '){
        pedazos.push_back("");
        b++;
        continue;
      }
      pedazos[pedazos.size() - 1] += texto[b];
      b++;
    }
    for(int i = 0; i < r1.size(); i++){
      if(r1[i] == pedazos[0]){
        for(int j = i; j < r1.size(); j++){
          if(r2[j] == pedazos[1]){
            for(int k = j; k < r1.size(); k++){
              if(r3[k] == pedazos[2]){
                if(pedazos.size() == 3) return 1;
                else{
                  pedazos.erase(pedazos.begin(), pedazos.begin());
                  for(int a = 0; a < r1.size(); a++){
                    if(r1[i] == pedazos[0]){
                      for(int b = a; b < r1.size(); b++){
                        if(r2[j] == pedazos[1]){
                          for(int c = b; c < r1.size(); c++){
                            if(r3[c] == pedazos[2]){
                              if(pedazos.size() == 4) return 1;
                              else{
                                for(int d = 0; d < r1.size(); d++){
                                  if(r1[d] == pedazos[0]){
                                    for(int e = d; e < r1.size(); e++){
                                      if(r2[e] == pedazos[1]){
                                        for(int f = e; f < r1.size(); f++){
                                          if(r3[f] == pedazos[2]){
                                            return 1;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                              }
                            }
                          }
                        }
                      }
                    }
                }
              }
            }
          }
        }
      }
    }
    }
    return 0;
}
