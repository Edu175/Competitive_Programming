#include "treasure.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sjdhg:v)cout<<sjdhg<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll D=2.5e4,B=17,NB=73,ND=5;

vector<int> encodeSmall(vector<pair<int, int>> a) {
	ll B=20;
	sort(ALL(a));
	vector<int>p;
	ll n=SZ(a);
	fore(i,0,n){
		ll v=a[i].fst;
		v=2*v;
		p.pb(v);
	}
	vector<ll>bits;
	fore(i,0,n){
		fore(j,0,29)bits.pb(a[i].snd>>j&1);
	}
	vector<ll>ys;
	for(ll s=0;s<SZ(bits);s+=B){
		ll e=min((ll)SZ(bits),s+B);
		ll v=0;
		fore(j,0,min(B,e-s))v|=bits[s+j]<<j;
		ys.pb(v);
	}
	fore(i,0,SZ(ys)){
		ll v=(i<<(B+1))+ys[i]*2+1;
		p.pb(v);
	}
	return p;
}
vector<pair<int, int>> decodeSmall(vector<int> p) {
	ll B=20;
	vector<pair<int,int>>a;
	for(auto v:p){
		if(!(v&1))a.pb({v>>1,0});
	}
	sort(ALL(a));
	vector<ll>ys(SZ(p)-SZ(a));
	for(auto v:p)if(v&1){
		v>>=1;
		ys[v>>B]=v&((1ll<<B)-1);
	}
	queue<ll>bits;
	for(auto v:ys){
		fore(j,0,B)bits.push(v>>j&1);
	}
	fore(i,0,SZ(a)){
		fore(j,0,29)a[i].snd|=(bits.front()<<j),bits.pop();
	}
	return a;
}

vector<int> encode(vector<pair<int, int>> a) {
	if(SZ(a)<50)return encodeSmall(a);
	sort(ALL(a),[&](ii a, ii b){
		ii c={a.fst,a.snd&1};
		ii d={b.fst,b.snd&1};
		return c<d;
	});
	vector<int>p;
	ll n=SZ(a);
	fore(i,0,n){
		ll v=a[i].fst;
		v=2*v+a[i].snd%2;
		v=2*v;
		p.pb(v);
	}
	vector<ll>bits;
	fore(i,0,n){
		fore(j,1,29)bits.pb(a[i].snd>>j&1);
	}
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	// imp(bits);
	vector<ll>ys;
	for(ll s=0;s<SZ(bits);s+=B){
		ll e=min((ll)SZ(bits),s+B);
		ll v=0;
		fore(j,0,min(B,e-s))v|=bits[s+j]<<j;
		ys.pb(v);
	}
	// imp(ys);
	
	fore(i,0,SZ(ys)){
		ll v=(i<<(B+1))+ys[i]*2+1;
		p.pb(v);
	}
	return p;
}

vector<pair<int, int>> decode(vector<int> p) {
	// cout<<"decode\n";
	vector<pair<int,int>>a;
	for(auto v:p){
		if(!(v&1))a.pb({v>>2,v>>1&1});
	}
	if(SZ(a)<50)return decodeSmall(p);
	sort(ALL(a));
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	vector<ll>ys(SZ(p)-SZ(a));
	for(auto v:p)if(v&1){
		v>>=1;
		ys[v>>B]=v&((1ll<<B)-1);
	}
	// imp(ys);
	queue<ll>bits;
	for(auto v:ys){
		fore(j,0,B)bits.push(v>>j&1);//,cout<<(v>>j&1)<<" ";
	}
	// cout<<"\n";
	fore(i,0,SZ(a)){
		fore(j,0,29)a[i].snd|=(bits.front()<<j),bits.pop();
	}
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	// cout<<"return\n";
	return a;
}