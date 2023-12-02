#include <string>
#include <vector>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    bool solucion=false;
    int res=0;
    vector <int> espacios;
    int g=0;
    int h=0;
    for(int i=0; i < texto.size(); i++){
        if(texto[i] == ' '){
            espacios[g] = i;
            g++;
        }
    }

    vector <string> palabras(espacios.size());

    for(int p=0; p < palabras.size(); p++){
    for(int b=0; b < espacios.size(); b++){
        for(int c=0; c + b < espacios[b + 1]; c++){  //palabra x palabra en el string
            palabras[p] += texto[espacios[b] + c];
        }
    } }

   /* for(int q=0; q < palabras.size() - 1; q++){ //agarra cada par de palabras
        r1[q] = palabras[q]
        r2[q] = palabras[q + 1]
        r3[q] = palabras[q + 2]
    }*/

    for(int q=0; q < palabras.size() - 1; q++){ // detecta
        while(h < r1.size()){
        if(palabras[q] == r1[h] && palabras[q+1] == r2[h]){
            solucion = true;
            h = r1.size() + 1;
        }else{
          h++;
        }
        }

    }

    if(solucion == true){
        res = 1;
    }
    return res;


}
