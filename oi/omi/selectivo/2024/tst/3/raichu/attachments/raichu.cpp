#include "Raichu.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfgdfh:v)cout<<dfgdfh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll idx=0;
int Raichu(int N, int m) {
	ll n=__builtin_ctz(N);
	ll k=14;
	if(m==10)k=10;
	ll mod=1ll<<(n-k);
	ll p=0;
	fore(i,0,k)p|=leer(i)<<i;
	random_device rd;
	mt19937 rng(rd());
	// ll sd; srand((ll)&sd);
	ll num=rng()%mod;
	// if(!idx++)cout<<num<<" "<<mod<<" num\n";
	// cout<<"llamada "<<idx++<<": "<<p<<"\n";
	// if(p%(1ll<<k)==(N-1)%(1ll<<k))cout<<"flip "<<idx++<<": "<<num<<" num\n";
	if(p%(1ll<<k)==(N-1)%(1ll<<k)&&num==0)return 1;
	p=(p+1)%(1ll<<k);
	fore(i,0,k){
		modificar(i,p>>i&1);
	}
	return 0;
}