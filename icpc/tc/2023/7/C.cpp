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
const ll MAXN=1e6+5;
vector<ii> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(auto [v,w]:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;
		do{x=st.top();st.pop();cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	mset(idx,0);qidx=0;
	mset(cmp,-1);qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}

ll gs(ll n){return n*(n-1)/2;}

ll val(ll n){
	ll l=0,r=n+5;
	while(r-l>1){
		ll m=(l+r)/2;
		if(gs(m)>n)r=m;
		else l=m;
	}
	ll s=l; // cantidad de pasos
	ll res=n*s;
	ll sac=(s-1)*s/2+(s-1)*s*(2*s-1)/6;
	assert(sac%2==0); sac/=2;
	res-=sac;
	// cout<<"val "<<n<<": "<<res<<"\n";
	return res;
}
vector<ii> dag[MAXN];

ll dp[MAXN];
ll v[MAXN];
ll f(ll x){
	// cout<<"pinga "<<x<<"\n";
	auto &res=dp[x];
	if(res!=-1)return res;
	res=0;
	for(auto [y,w]:dag[x])res=max(res,w+f(y));
	res+=v[x];
	// cout<<x<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		// g[v].pb({u,w});
	}
	scc();
	fore(i,0,n)for(auto [j,w]:g[i]){
		ll x=cmp[i],y=cmp[j];
		if(x==y)v[x]+=val(w);
		else dag[x].pb({y,w});
	}
	mset(dp,-1);
	ll s; cin>>s; s--;
	// cout<<s<<": "<<cmp[s]<<"\n";
	s=cmp[s];
	ll res=f(s);
	cout<<res<<"\n";
	return 0;
}
