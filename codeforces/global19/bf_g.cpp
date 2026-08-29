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

ll n;
/*
set<vv> st;
void dfs(vv a){
	sort(ALL(a));
	if(a.back()>10)return;
	if(st.count(a))return;
	cerr<<"dfs "; imp(a)
	st.insert(a);
	fore(i,0,n)fore(j,i+1,n){
		auto b=a;
		b.erase(b.begin()+j);
		b.erase(b.begin()+i);
		b.pb(a[i]+a[j]);
		b.pb(abs(a[i]-a[j]));
		dfs(b);
	}
}
*/

ll Plgt(ll x){
	ll r=1ll<<__lg(x); // piso
	if(r<x)r*=2;
	return r;
}

void bfs(vv a){
	ll bound=Plgt(n);
	queue<pair<ll,vv>> q;
	q.push({0,a});
	map<vv,vv> fa; fa[a]={};
	ll prev=-1;
	while(SZ(q)){
		auto [d,a]=q.front(); q.pop();
		// cerr<<d<<": ";imp(a)
		if(d>prev)cerr<<"new d "<<d<<"\n";
		prev=d;
		fore(i,0,n)fore(j,i+1,n){
			auto b=a;
			b.erase(b.begin()+j);
			b.erase(b.begin()+i);
			b.pb(a[i]+a[j]);
			b.pb(abs(a[i]-a[j]));
			sort(ALL(b));
			if(b.back()>bound)continue;
			if(fa.count(b))continue;

			fa[b]=a;
			// st.insert(b);
			q.push({d+1,b});

			if(b==vv(n,b[0])){
				fa[b]=a;
				cout<<d+1<<": "<<b[0]<<"\n";
				vector<vv> path;
				for(auto s=b;SZ(fa[s]);s=fa[s])path.pb(s);
				reverse(ALL(path));
				for(auto v:path)imp(v)
				return;
			}
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vv a(n); iota(ALL(a),1);
		bfs(a);
	}
	return 0;
}
