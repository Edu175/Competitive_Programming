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
    if(v.size() < 1000){
        for(int i : v)
            if(k == i)
                return true;
    }else{
    int lo = 0;
    int hi = v.size() - 1;
    int mid;
    do{
        mid = (lo + hi) / 2 + 1;
        if(k == v[mid])
            return true;
        if(k > v[mid])
            lo = mid;
        else
            hi = mid;
    } while (true);
    }
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
