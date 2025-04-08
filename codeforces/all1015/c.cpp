#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii> a(n);
		map<ii,vv>mp;
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd,mp[a[i]].pb(i);
		vv to(n),vis(n);
		ll fg=1,un=0;
		fore(i,0,n)if(!vis[i]){
			auto p=a[i]; swap(p.fst,p.snd);
			auto &v=mp[p];
			while(SZ(v)&&vis[v.back()])v.pop_back();
			if(!SZ(v)){fg=0;break;}
			to[i]=v.back(); v.pop_back();
			to[to[i]]=i;
			vis[to[i]]=1;
			vis[i]=1;
			un+=to[i]==i;
		}
		fg&=un==(n&1);
		if(!fg){cout<<"-1\n";continue;}
		vector<ii>res;
		vv p(n); iota(ALL(p),0);
		vv h(n); iota(ALL(h),0);
		auto sw=[&](ll i, ll j){
			if(i==j)return;
			res.pb({i,j});
			ll ix=h[i],jx=h[j];
			swap(h[i],h[j]);
			swap(p[ix],p[jx]);
		};
		if(n&1){
			ll w=-1;
			fore(i,0,n)if(to[i]==i)w=i;
			assert(w!=-1);
			sw(w,n/2);
		}
		fore(i,0,n/2){
			ll x=h[i],y=to[x],j=p[y],obj=n-1-i;
			sw(j,obj);
		}
		cout<<SZ(res)<<"\n";
		for(auto [i,j]:res)cout<<i+1<<" "<<j+1<<"\n";
	}
	return 0;
}
