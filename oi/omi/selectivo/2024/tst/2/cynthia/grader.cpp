#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto slkgh:v)cout<<slkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int Decision(int N); 
void Cynthia(int N);
vector<vector<int>> Juan(int N);

vector<vector<int>>__mov;
ll __n;
ll __cnt=0;
ll __won=0;
vector<int>__a;
vector<int> Inicializa(vector<int>A){
	__n=SZ(A);
	__a=A;
	__mov=Juan(__n);
	__cnt=1;
	__won=0;
	return __mov[0];
}
void __apply(vector<int>tr){
	fore(i,0,__n)__a[i]^=tr[i];
	if(__a==vector<int>(__n,0))__won=1;
}
vector<int> Turno(int X){
	cout<<"turno "<<__cnt<<endl;
	imp(__a);
	rotate(__a.begin(),__a.begin()+X,__a.end());
	__apply(__mov[__cnt-1]);
	imp(__a);
	if(__cnt==SZ(__mov))return vector<int>(__n,-1);
	return __mov[__cnt++];
}

int main(){
	ll t; cin>>t;
	while(t--){
		cin>>__n;
		ll pl=Decision(__n);
		Cynthia(__n);
		if(pl!=__won)cout<<"WA ";
		else cout<<"OK ";
		cout<<"gano ";
		if(!__won)cout<<"Cynthia\n";
		else cout<<"Juan\n";
	}
	return 0;
}
