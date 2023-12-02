#include <string>
#include <vector>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    int r=0;
    vector<string> v;
    
    string str;

     char espacio = ' ';

    for(int i=0;i<texto.size();i++){

     if(texto[i] == espacio || i+1==texto.size()){

         for(int j=0;j<str.size();j++){
            str.pop_back();
        }

       }else{

       str.push_back(texto[i]);

     }
    }

    for(int i=0;i<v.size();i++){
     
     if(r1[i]==v[i] && r2[i]==v[i+1] && r3[i]==v[i+2]){
        r=1;
     }

    }
    





    return r;
}
