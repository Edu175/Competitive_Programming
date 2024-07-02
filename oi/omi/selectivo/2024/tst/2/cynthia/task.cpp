#include "Juego.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto slkgh:v)cout<<slkgh<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int Decision(int n) {
	if(__builtin_popcountll(n)==1)return 1;
	return 0;
}
vector<int>a__;
void apply(vector<int>tr){
	fore(i,0,SZ(tr))a__[i]^=tr[i];
}

vector<int> rot(ll x, vector<int>mov){
	rotate(a__.begin(),a__.begin()+x,a__.end());
	apply(mov);
	return Turno(x);
}
void Cynthia(int n) {
	// return;
	a__=vector<int>(n); a__[0]=1;
	auto mov=Inicializa(a__);
	ll p=1ll<<__builtin_ctzll(n),s=0;
	while(mov[0]!=-1){
		ll r=-1;
		fore(x,0,n){
			if((a__[s]^mov[(s-x+n)%n])!=(a__[(s+p)%n]^mov[(s+p-x+n)%n])){
				r=x;
				break;
			}
		}
		/*cout<<s<<" "<<p<<": "<<r<<endl;
		imp(a__);
		imp(mov);*/
		assert((__builtin_popcountll(n)==1)==(r==-1));
		if(r==-1)r=rand()%n;
		rot(r,mov);s=(s-r+n)%n;
		mov=Turno(r);
	}
	
	
	
}
// void Cynthia(int N){}
vector<vector<int>> Juan(int n) {
	if(n==1)return {{1}};
	if(n==2)return {{1,1},{1,0},{1,1}};
	if(n==4)return {
		{1,1,1,1},
		{1,0,1,0},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{1,1,0,0},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{1,0,1,0},
		{1,1,1,1},
		{1,1,0,0},
		{1,1,1,1},
		{1,0,1,0},
		{1,1,1,1}
	};
	vector<vector<int>>ret(1ll<<n,vector<int>(n,0));
	fore(i,1,SZ(ret)){
		fore(j,0,n)ret[i][j]=rand()&1;
	}
	return ret;
}