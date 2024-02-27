#include "sequence.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,apio=b;i<apio;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto slkdh:v)cout<<slkdh<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll INF=5e6;
struct node{
	ll mxp,mnp,mxs,mns,sum;
};
node oper(node a, node b){
	a.mxp=max(a.mxp,a.sum+b.mxp);
	a.mnp=min(a.mnp,a.sum+b.mnp);
	a.mxs=max(a.mxs+b.sum,b.mxs);
	a.mns=min(a.mns+b.sum,b.mns);
	a.sum+=b.sum;
	return a;
}
node NEUT({-INF,INF,-INF,INF,0});
struct STcustom{
	vector<node>t; ll n;
	STcustom(ll n):t(2*n+5,node({0,0,0,0,0})),n(n){}
	void upd(ll p, ll v){
		p+=n;
		t[p].mxp+=v,t[p].mnp+=v,t[p].mxs+=v,t[p].mns+=v,t[p].sum+=v;
		for(;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
const ll MAXN=5e5+5;
ll n;
ll a[MAXN];
vector<ll>pos[MAXN];
vector<node> pre[MAXN],suf[MAXN];

bool can(ll x){
	fore(i,0,n){
		fore(s,0,SZ(pos[i])){
			ll e=s+x-1;
			if(e>=SZ(pos[i]))break;
			ll dif=pre[i][e].sum-pre[i][s].sum;
			if(dif<=0){
				if(dif+pre[i][s].mxs+suf[i][e].mxp+e-s+1>=0)return 1;
			}
			else {
				if(dif+pre[i][s].mns+suf[i][e].mnp-(e-s+1)<=0)return 1;
			}
		}
	}
	return 0;
}
int sequence(int N, std::vector<int> A) {
	n=N;
	fore(i,0,n)a[i]=A[i]-1;
	fore(i,0,n)pos[a[i]].pb(i);
	STcustom st(n);
	fore(i,0,n)st.upd(i,1);
	fore(i,0,n){
		for(auto j:pos[i])st.upd(j,-1);
		pre[i].resize(SZ(pos[i]));
		suf[i].resize(SZ(pos[i]));
		fore(j,0,SZ(pos[i])){
			pre[i][j]=st.query(0,pos[i][j]+1);
			suf[i][j]=st.query(pos[i][j],n);
		}
		for(auto j:pos[i])st.upd(j,-1);
	}
	ll l=1,r=n+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	return r;
}
