#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int size= x.size();
    int X=0;
    cout <<size<< endl;
    for (int i=-1 ; i<size ; i++){
            int u=i+1;
        X+= x[i] + x[u];
    i++;
    }
return X;
}
