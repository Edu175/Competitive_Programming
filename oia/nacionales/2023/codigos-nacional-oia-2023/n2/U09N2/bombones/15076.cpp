#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int N = x.size();
    int sumK = 0;
    long long sumX = 0;
    long long cajas = 0;

    long long sumadeunos = 0;
    //int max = x[0];
    vector<int> indices;
    for (int index = 0; index < N; index++){
        if(x[index] == 1){
            sumadeunos+=1;
        }
    }

    if(sumadeunos == N && K > 1){
        return cajas;
    } else if (sumadeunos == N and K ==1){
        cajas+=sumadeunos;
        return cajas;
    }

}
