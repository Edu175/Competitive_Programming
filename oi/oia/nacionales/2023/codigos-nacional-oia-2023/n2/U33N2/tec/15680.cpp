#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tab;

void tablero(int N, vector<int> &A, vector<int> &B) {
    tab = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    for(int i = 0; i < A.size(); i++){
        tab[A[i]][B[i]] = 1;
        tab[B[i]][A[i]] = 1;
    }
}

bool controlo(int k, vector<int> v){
    if(v.size() < 3){
        for(int i : v)
            if(i == k)
                return true;
        return false;
    }
    int lo = 0;
    int hi = v.size() - 1;
    int mid;
    while(true){
        mid = (lo + hi) / 2;
        if(k == v[mid])
            return true;
        if(mid == 0 || mid == v.size() - 1)
            return false;
        if(k > v[mid])
            lo = mid;
        else
            hi = mid;
    }
}

int con_quien_comercio(vector<int> &controlados) {
    sort(controlados.begin(), controlados.end());
    for(int desde : controlados){
        for(int hacia = 1; hacia <= tab.size(); hacia++){
            if(tab[desde][hacia] == 1){
                if(!controlo(hacia, controlados))
                    return hacia;
            }
        }
    }
    return -1;
}
