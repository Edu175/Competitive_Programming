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
const ll MAXN=2e5+5;

ll res=0;
struct node{
	map<ll,ll> oc;
	set<ii>st;
	ll sz=0;
	node(){}
	node(ll v):sz(1){st={{1,v}},oc[v]=1;}
	void merge(node a){
		sz+=a.sz;
		for(auto [w,q]:a.oc){
			st.erase({oc[w],w});
			oc[w]+=q;
			st.insert({oc[w],w});
		}
	}
	void process(){
		assert(sz);
		auto mx=st.rbegin()->fst;
		ll cost=sz-mx;
		// cout<<"process "<<mx<<": "<<cost<<"\n";
		res+=cost;
		while(st.begin()->fst<mx){
			auto [q,w]=*st.begin(); st.erase(st.begin());
			oc.erase(w);
		}
		if(mx>1){
			st.clear();
			for(auto &i:oc){
				assert(i.snd==mx);
				i.snd=1,st.insert({1,i.fst});
			}
		}
		sz=1;
	}
};

vv g[MAXN];
ll a[MAXN];
node dfs(ll x, ll fa, ll xr){
	xr^=a[x];
	ll hoj=1;
	node ans;
	for(auto y:g[x])if(y!=fa){
		hoj=0;
		auto cur=dfs(y,x,xr);
		if(SZ(ans.oc)<SZ(cur.oc))swap(ans,cur);
		ans.merge(cur);
	}
	if(hoj){
		// cout<<"hoja "<<x<<": "<<xr<<"\n";
		return node(xr);
	}
	// cout<<x<<" ";
	ans.process();
	return ans;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto ans=dfs(0,-1,0);
	if(!ans.oc.count(0))res++;
	cout<<res<<"\n";
	return 0;
}
