#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto dflg:v)cout<<dflg<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5e5+5,MAXV=(1ll<<20)+100;
vector<ii>g[MAXV];
vv eulerWalk(ll nedges, ll src=0) {
	auto gr=g;
	ll n = MAXV;
	vv D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		ll x = s.back(), y, e, &it = its[x], end = SZ(gr[x]);
		if (it == end){ ret.pb(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.pb(y);
		}}
	for (ll x : D) if (x < 0 || SZ(ret) != nedges+1
	||ret.back()!=ret[0]) return {};
	reverse(ALL(ret));
	ret.pop_back();
	return ret;
}
ii a[MAXN];
ll n;
vv camino(ll k){
	vector<ll>bor;
	ll mk=(1ll<<k)-1,cnt=0;
	fore(i,0,n){
		ll u=a[i].fst&mk,v=a[i].snd&mk;
		g[u].pb({v,cnt++});
		if(u!=v)g[v].pb({u,cnt-1});
		bor.pb(u),bor.pb(v);
	}
	vv r=eulerWalk(n,bor[0]);
	// cout<<" camino "<<k<<": "; imp(r);
	for(auto i:bor)g[i].clear();
	return r;
}
// ll value(vector<ii>a){
// 	ll k=20;
// 	cout<<SZ(a)<<" sz "<<endl;
// 	for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
// 	fore(i,0,n){
// 		k=min(k,(ll)__builtin_ctzll(a[i].snd^a[(i+1)%n].fst));
// 	}
// 	return k;
// }

// bool check(vector<ll>c, ll k){
// 	vector<ii>b;
// 	fore(i,0,SZ(c))if(i%2==0){
// 		ll idx=min(c[i],c[i+1])/2;
// 		ll sw=c[i]>c[i+1];
// 		if(sw)b.pb({a[idx].snd,a[idx].fst});
// 		else b.pb(a[idx]);
// 	}
// 	return value(b)==k;
// }

int main(){JET
	cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vv res;
	ll l=0,r=20;
	while(l<=r){
		ll m=(l+r)/2;
		res=camino(m);
		if(SZ(res))l=m+1;
		else r=m-1;
	}
	res=camino(r);
	cout<<r<<"\n";
	map<ii,vector<ll>>mp;
	ll mk=(1ll<<r)-1;
	fore(i,0,n)mp[{a[i].fst&mk,a[i].snd&mk}].pb(i);
	// for(auto i:res)cout<<i<<" ";;cout<<" camino"<<endl;
	vector<ll>ans;
	fore(i,0,SZ(res)){
		auto x=res[i],y=res[(i+1)%SZ(res)];
		if(SZ((mp[{x,y}]))){
			auto &dat=mp[{x,y}];
			ll idx=dat.back();
			dat.pop_back();
			ans.pb(2*idx),ans.pb(2*idx+1);
		}
		else {
			auto &dat=mp[{y,x}];
			assert(SZ(dat));
			ll idx=dat.back();
			dat.pop_back();
			ans.pb(2*idx+1),ans.pb(2*idx);
		}
	}
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	// assert(check(ans,r));
}