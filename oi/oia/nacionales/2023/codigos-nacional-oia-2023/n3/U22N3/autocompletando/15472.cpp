#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    
    bool pool;
    
    for(int i=0; i<r1.size(); i++){ //bucle for para generar arreglos de todos los r1, r2 y r3
        if(r1[i]=r1[r1.size()-1]||r2[i]=r2[r2.size()]){ //ciclo if que sugiere r3[i] como siguiente palabra si la anteultima palabra fue r1[i] y la ultima fue r2[i]
            return r3[i];
        }
    }
    
    for(int i=0; i<r1.size(); i++){  //bucle for que recorre todos los arreglos
        if(pool==1){ // ciclo if que retorna 1 si es posible generar el texto con el editor y 0 en caso contrario.
            return 1;
        } else return 0;
    }
}