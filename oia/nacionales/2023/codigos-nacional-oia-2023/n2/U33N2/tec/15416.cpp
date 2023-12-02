#include <string>
#include <vector>

using namespace std;

vector<vector<int>> tab;

void tablero(int N, vector<int> &A, vector<int> &B) {
    tab = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    for(int i = 0; i < A.size(); i++){
        tab[A[i]][B[i]] = 1;
        tab[B[i]][A[i]] = 1;
    }
}

bool is_in(int k, vector<int> v){
    for(int i = 0; i < v.size(); i++)
        if(k == v[i])
            return true;
    return false;
}

int con_quien_comercio(vector<int> &controlados) {
    for(int desde : controlados){
        for(int hacia = 1; hacia <= tab.size(); hacia++){
            if(tab[desde][hacia] == 1){
                if(!is_in(hacia, controlados)){
                    return hacia;
                }
            }
        }
    }
    return -1;
}
