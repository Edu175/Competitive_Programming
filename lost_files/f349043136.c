#include "coreputer.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

ll n;
vector<ll>a,b,ones;
ll p;

ll ask(ll r){ // ]
	vector<ll>v;
	fore(i,0,n){
		if(b[i])continue;
		if(a[i]||i<=r)v.pb(i);
	}
	return run_diagnostic(n);
}

std::vector<int> malfunctioning_cores(int N) {
	n=N;
	b.resize(n),a.resize(n);
	return {};
}
