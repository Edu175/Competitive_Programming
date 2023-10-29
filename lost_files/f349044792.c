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
	return run_diagnostic(v);
}

std::vector<int> malfunctioning_cores(int N) {
	n=N;
	b.resize(n),a.resize(n);
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(ask(m)!=-1)r=m-1;
		else l=m+1;
	}
	p=l;
	vector<ll>res(n);
	b[p]=1;
	res[p]=1;
	fore(i,p+1,n){
		if(ask(i)!=-1)b[i]=1,res[i]=1;
	}
	b[p]=0; a[p]=1;
	for(ll i=p-1;i>=0;i--){
		if(ask(i-1)==-1)b[i]=1,res[i]=1;
	}
	return res;
}
