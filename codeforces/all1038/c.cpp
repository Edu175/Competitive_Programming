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
		vector<ii> xs,ys;
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			xs.pb({a[i].fst,i});
			ys.pb({a[i].snd,i});
		}
		sort(ALL(xs));
		sort(ALL(ys));
		// for(auto i:xs)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		// for(auto i:ys)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		
		vv mk(n);
		fore(i,0,n)mk[xs[i].snd]|=i<n/2;
		fore(i,0,n)mk[ys[i].snd]|=2*(i<n/2);
		
		vector<vv> h(4);
		fore(i,0,n){
			h[mk[i]].pb(i);
			// cout<<i<<": "<<mk[i]<<"\n";
		}
		vector<ii>ans;
		fore(w,0,2){
			auto &u=h[w];
			auto &v=h[w^3];
			assert(SZ(u)==SZ(v));
			
			fore(i,0,SZ(u))ans.pb({u[i],v[i]});
			
		}
		
		for(auto i:ans)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	return 0;
}
