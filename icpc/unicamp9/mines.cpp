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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=1e5+5;
vector<ll> g[2*MAXN];

ll n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;
void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(ll n){
	fore(i,0,n)idx[i]=0,cmp[i]=-1;
	qidx=0; qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
	n2=qcmp;
}

void add(ll x, ll y){
	g[x].pb(y);
}
ll cnt=0;
struct Rang{
	ll n; vector<ll>k;
	Rang(){}
	Rang(ll n):n(n),k(2*n+5){
		fore(i,0,n){
			k[i]=cnt++;
			k[i+n]=i;
		}
		fore(i,1,n){
			add(k[i],k[2*i]);
			add(k[i],k[2*i+1]);
		}
	}
	void query(ll l, ll r, ll c){
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)add(c,k[l++]);
			if(r&1)add(c,k[--r]);
		}
	}
};
vector<bitset<MAXN>>c;
ll vis[2*MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		dfs(y);
		c[x]|=c[y];
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,2*n+5){
			g[i].clear();
			vis[i]=0;
			
		}
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		Rang rg(n);
		fore(i,0,n){
			ll l=lower_bound(ALL(a),ii({a[i].fst-a[i].snd,-1}))-a.begin();
			ll r=lower_bound(ALL(a),ii({a[i].fst+a[i].snd+1,-1}))-a.begin();
			rg.query(l,r,i);
		}
		scc(n+cnt);
		c.clear();
		c.resize(n2);
		fore(i,0,n)c[cmp[i]][i]=1;
		fore(i,0,n){
			cout<<i<<": "<<cmp[i]<<"\n";
		}
		fore(i,0,n){
			if(i)cout<<" ";
			cout<<c[cmp[i]].count();
		}
		cout<<"\n";
	}
	return 0;
}
