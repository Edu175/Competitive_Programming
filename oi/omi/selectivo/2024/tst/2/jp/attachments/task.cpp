#include "alumnos.h"
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

int Reto_Sebas(int N) {
	ll n=N;
	auto sig=[&](ll x){
		if(x==0)return x;
		return x/abs(x);
	};
	ll res=-1;
	vector<ll>mem(n,-1),vis(n);
	auto ask=[&](ll i){
		ll &v=mem[i];
		if(vis[i])return v;
		vis[i]=1;
		v=valor(i)-valor((i+n/2)%n);
		if(v==0)res=i;
		return sig(v);
	};
	ll s=ask(0);
	ll l=0,r=n/2-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(ask(m)==s)l=m+1;
		else r=m-1;
	}
	fore(i,max(0ll,l-5),min(n,l+5))ask(i);
	if((valor(0)-valor(n/2))&1)assert(res==-1);
	// if(l>=0&&l<n)ask(l);
	// if(r>=0&&r<n)ask(r);
	// cout<<"mi res "<<res<<"\n";
	return res;
}