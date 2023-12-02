#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x)
{
	vector <int> t;
	int hola;
    int contador=0;
	int mary;
	
	for(int i=0; i < K ; i++)
	{
	    int che = x[i]+x[i+1];
        t.push_back(che);
    }
    
    for(int i=0; i < t.size() ; i++)
    {
		hola = x[i]+x[i+1];
	    mary = hola - K;
	    ++++contador;
	}
	
    return contador;
}

int main() 
{
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
  

