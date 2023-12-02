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
    for(string i : pedazos) cout << i << endl;
    for(int i = 0; i < r1.size(); i++){
      if(r1[i] == pedazos[0]){
        for(int j = i; j < r1.size(); j++){
          if(r2[j] == pedazos[1]){
            for(int k = j; k < r1.size(); k++){
              if(r3[k] == pedazos[2]){
                if(pedazos.size() == 3) return 1;
              }
            }
          }
        }
      }
    }
    return 0;
}
