#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv eulerWalk(vector<vector<ii>>& gr, ll nedges, ll src=0) {
	ll n = SZ(gr);
	vv D(n), its(n), eu(nedges), ret;
	vector<ii> s = {{src,-1}};
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		auto [x,i] = s.back();
		ll &it = its[x], end = SZ(gr[x]);
		if (it == end) { ret.pb(i), s.pop_back(); continue; }
		auto [y, e] = gr[x][it++];
		if (!eu[e]) D[x]--, D[y]++, eu[e] = 1, s.pb({y,e});
	}
	for (ll x : D) if (x < 0 || SZ(ret) != nedges+1) return {};
	ret.pop_back();
	return {ret.rbegin(), ret.rend()};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),d(n);
		vector<vector<ii>> gr(n);
		fore(i,0,n){
			cin>>a[i]; a[i]--;
			d[i]++; d[a[i]]--;
			gr[i].pb({a[i],i});
		}
		bool good=1;
		ll cnt=n,sum=0;
		fore(i,0,n){
			sum+=d[i];
			if(sum>0){good=0;break;}
			if(sum<0){
				gr[i].pb({i+1,cnt++});
				d[i]++,d[i+1]--; sum++;
			}
		}
		if(!good){
			cout<<"No\n";
			continue;
		}
		ll r=0;
		fore(i,0,n)while(d[i]<0){
			while(r<n&&d[r]<=0)r++;
			assert(r<n);
			gr[i].pb({r,cnt++});
			d[i]++; d[r]--;
		}
		auto got=eulerWalk(gr,cnt);
		if(!SZ(got)){
			cout<<"No\n";
			continue;
		}
		vv path;
		for(auto i:got)if(i<n)path.pb(i);
		cout<<"Yes\n";
		for(auto i:path)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
