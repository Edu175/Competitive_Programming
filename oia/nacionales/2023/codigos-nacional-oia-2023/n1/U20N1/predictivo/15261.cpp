#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*||*/
int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {

    int ok=0, posicion=0;
    string texto2;
    vector <string> palabras (1);
    for (int y=0; y<texto.size(); y++){
          if (texto[y] != ' ') {
              palabras[posicion]=palabras[posicion]+texto[y];
          } else {
              palabras.push_back("");
              posicion++;
          }
    }
    for (int h=0; h<r1.size(); h++) {
        for (int d=0; d<palabras.size(); d++) {
            if (r1[h]==palabras[d] && r2[h]==palabras[d+1] && r3[h]==palabras[d+2]) {
                ok=1;
            }
        }
    }

    return ok;
}
