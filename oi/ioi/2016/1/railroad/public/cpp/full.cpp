#include "railroad.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkfjhg:v)cout<<dkfjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=4e5+5,INF=1e15;
ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return 0;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y],uf[y]=x;
	return 1;
}
ll mst(vector<pair<ll,ii>>&ed){
	sort(ALL(ed));
	mset(uf,-1);
	ll res=0;
	for(auto [w,pa]:ed){
		if(uf_join(pa.fst,pa.snd))res+=w;
	}
	return res;
}

long long plan_roller_coaster(std::vector<int> A, std::vector<int> B) {
    vector<ll>a,b;
	for(auto i:A)a.pb(i);
	for(auto i:B)b.pb(i);
	a.pb(INF); b.pb(1);
	ll n=SZ(a);
	vector<ii>ev;
	fore(i,0,n){
		ev.pb({a[i],1});
		ev.pb({b[i],-1});
	}
	sort(ALL(ev));
	vector<pair<ll,ii>>ed;
	fore(i,0,n)ed.pb({0,{a[i],b[i]}});
	ll s=0,res=0;
	fore(i,0,SZ(ev)){
		s+=ev[i].snd;
		if(i<SZ(ev)-1&&ev[i].fst!=ev[i+1].fst){
			ll u=ev[i].fst,v=ev[i+1].fst;
			ll d=v-u;
			if(s>0)res+=d*s;
			if(s)ed.pb({0,{u,v}});
			ed.pb({d,{u,v}});
		}
	}
	
	//compress
	vector<ll>com;
	fore(i,0,n)com.pb(a[i]),com.pb(b[i]);
	sort(ALL(com));
	auto _com=com; com.clear();
	for(auto i:_com)if(!SZ(com)||i!=com.back())com.pb(i);
	auto getid=[&](ll v){
		return lower_bound(ALL(com),v)-com.begin();
	};
	
	for(auto &[w,pa]:ed){
		auto &[u,v]=pa;
		u=getid(u),v=getid(v);
	}
	res+=mst(ed);
	return res;
}
