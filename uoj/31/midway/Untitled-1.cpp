#include <bits/stdc++.h>
using namespace std;

int suma(int x, int y){
	return x+y;
}

// tamaño del string + 5

int f(string s){
	int z=s.size();
	z+=5;
	return z;
}

int k=5;
vector<int> v;

void agregar(int x){
	k+=x;
	v.push_back(x);
}

int main(){
	// int a,b; cin>>a>>b;
	// cout << suma(a,b) << endl;
	agregar(3);
	agregar(8);
	cout<<k<<endl;
	for(auto i:v)cout<<i<<" ";
	cout<<endl;
	return 0;
}