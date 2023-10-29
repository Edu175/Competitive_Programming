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
ll did[1<<16];

ll run(vector<ll>v){
	cout<<"run: ";
	imp(v);
	ll mk=0;
	for(auto i:v)mk+=1ll<<i;
	ll &res=did[mk];
	if(res!=-1)return res;
	return res=run_diagnostic(v);
}

ll ask(ll r){ // ]
	vector<ll>v;
	fore(i,0,n){
		if(b[i])continue;
		if(a[i]||i<=r)v.pb(i);
	}
	return run(v);
}

std::vector<int> malfunctioning_cores(int N) {
	n=N;
	mset(did,-1);
	b.resize(n),a.resize(n);
	ll l=0,r=n-1;
	while(l<=r){
		cout<<l<<","<<r<<"\n";
		ll m=(l+r)/2;
		if(ask(m)!=-1)r=m-1;
		else l=m+1;
	}
	p=l;
	vector<ll>res(n);
	a[p]=1;
	res[p]=1;
	cout<<p<<"\n";
	//cout<<"primer\n";
	fore(i,p+1,n){
		//cout<<i<<": "<<ask(i)<<"\n";
		if(ask(i)!=-1)b[i]=1,res[i]=1;
	}
	//cout<<"segunda\n";
	b[p]=0; a[p]=1;
	for(ll i=p-1;i>0;i--){
		//cout<<i<<": "<<ask(i-1)<<"\n";
		if(ask(i-1)==-1)a[i]=1,res[i]=1;
	}
	return res;
}
