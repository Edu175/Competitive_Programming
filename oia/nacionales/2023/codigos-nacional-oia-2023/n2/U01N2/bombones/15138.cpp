#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> x;
    x.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> x[i0];
    }
    long long returnedValue;
    returnedValue = bombones(K, x);
    cout << returnedValue << "\n";
    return 0;
}


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    
    long long cajas;
    
    while(x[0] != 0){
		x[0] = x[0] - 1;
		cajas = cajas + 1;
	}
    
    return cajas;
}
