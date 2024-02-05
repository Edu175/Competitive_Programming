#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=(2e5)*2;
vector<ll> g[MAXN];//,g2[MAXN],set<ll> gst[MAXN];
vector<ll> G[MAXN];

ll n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;
void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
bool scc(){
	fore(i,0,3*n+5)idx[i]=0,cmp[i]=-1;//,g2[i].clear();gst[i].clear();
	qidx=0; qcmp=0;
	/*mset(idx,0); // NO TEST CASES
	mset(cmp,-1);*/
	fore(i,0,3*n+5)if(!idx[i])tjn(i);
	fore(i,0,n)if(cmp[i]==cmp[n+i])return 0;
	return 1;
	//fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	//fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
}

ll cv(ll i){
	if(i<n)return 2*n+i;
	return i;
}
vector<ll> range(ll l, ll r){
	l=max((ll)0,l);
	r=min(n,r);
	vector<ll>ret;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)ret.pb(cv(l++));
		if(r&1)ret.pb(cv(--r));
	}
	return ret;
}

bool can(ll k){
	fore(i,0,3*n+5)g[i]=G[i];
	fore(i,0,n){
		for(auto j:range(i-k+1,i))g[i].pb(j);
		for(auto j:range(i+1,i+k))g[i].pb(j);
	}
	return scc();
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		ll m; cin>>m;
		fore(i,0,n*3+5)G[i].clear();
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			G[n+u].pb(v);
			G[n+v].pb(u);
		}
		fore(i,0,n){
			G[cv(i)].pb(cv(2*i));
			G[cv(i)].pb(cv(2*i+1));
		}
		/*fore(i,0,3*n+5){
			cout<<i<<": ";
			for(auto j:G[i])cout<<j<<" ";
			cout<<"\n";
		}*/
		ll l=0,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	return 0;
}
