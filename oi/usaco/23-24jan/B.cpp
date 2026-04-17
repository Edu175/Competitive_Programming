#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skjdhf:v)cout<<skjdhf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ll>g[MAXN];
vector<ll>ord;
ll S[MAXN],E[MAXN],D[MAXN];
void dfs(ll x, ll fa=-1){
	S[x]=SZ(ord);
	ord.pb(x);
	for(auto y:g[x])if(y!=fa){
		D[y]=D[x]+1;
		dfs(y,x);
	}
	E[x]=SZ(ord);
}
bool cmp(ll a, ll b){return D[a]>D[b];}
int main(){FIN;
	ll n; cin>>n;
	vector<ll>p(n);
	fore(i,0,n)cin>>p[i],p[i]--;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	set<ll>st;
	fore(i,1,n){
		if(SZ(g[i])==1)st.insert(S[i]);
	}
	p.resize(SZ(st));
	sort(ALL(p),cmp);
	/*fore(i,0,n)cout<<i<<": "<<S[i]<<" "<<E[i]<<"\n";
	imp(st);
	imp(p);*/
	ll res=0;
	for(auto x:p){
		auto it=st.lower_bound(S[x]);
		if(it!=st.end()&&*it<E[x]){
			res++;
			st.erase(*it);
		}
	}
	cout<<res<<"\n";
	return 0;
}
