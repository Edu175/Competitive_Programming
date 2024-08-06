#include "popa.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcont=b;i<mxcont;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jfhg:v)cout<<jfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int solve(int n, int* L, int* R)
{
	fore(i,0,n)L[i]=R[i]=-1;
	auto gano=[&](ll i, ll j){
		return query(j,i,i,i);
	};
	vector<ll>v;
	fore(i,0,n){
		while(SZ(v)&&gano(i,v.back()))L[i]=v.back(),v.pop_back();
		if(SZ(v))R[v.back()]=i;
		v.pb(i);
	}
    return v[0];
}