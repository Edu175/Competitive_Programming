#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x)
{
	int hola;
    int contador=0;
	
	
    for(int i=0; i < K ; i++)
    {
		hola = x[i]+x[i+1];
	    hola = hola - K;
	    ++++contador;
	}
	
    return contador -1;
}

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
    int returnedValue;
    returnedValue = chocolates(K, x);
    cout << returnedValue << "\n";
    return 0;
}

