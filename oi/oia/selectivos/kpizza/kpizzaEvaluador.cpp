#include <bits/stdc++.h>

using namespace std;


int kpizza(int N);

vector<int> pizzaEntradaEvaluadorLocal;
int QUERIES=0;
int morder(int i)
{
	QUERIES++;
    cout << "morder(" << i << ") = ";
    if (i < 0 || i >= int(pizzaEntradaEvaluadorLocal.size()))
    {
        cout << "LLAMADA INVALIDA, EJECUCION FINALIZADA" << endl;
        exit(0);
    }
    cout << pizzaEntradaEvaluadorLocal[i] << endl;
    return pizzaEntradaEvaluadorLocal[i];
}
mt19937 rng;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int res; cin>>res;
	assert(N%res==0);
	int K=N/res;
	pizzaEntradaEvaluadorLocal.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        pizzaEntradaEvaluadorLocal[i0]=i0/K;
    }
	int d=rng()%N;
	#define nombre pizzaEntradaEvaluadorLocal
	rotate(nombre.begin(),nombre.begin()+d,nombre.end());
	// for(auto i:nombre)cout<<i<<" ";;cout<<" array"<<endl;
	#undef nombre
    int returnedValue;
    returnedValue = kpizza(N);
	if(returnedValue==res){
		cout<<"OK guessed correctly\n";
	}
	else {
		cout << "WA, answered " << returnedValue << endl;
	}
	cout<<QUERIES<<" queries\n";
	cout<<5 + (__lg(N-1)+1)<<" bound\n";
    return 0;
}
