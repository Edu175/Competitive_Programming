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
const ll MAXN=1e6+5,MOD=998244353;

vector<ll> g[MAXN],g2[MAXN]; set<ll> gst[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
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
void scc(){
	fore(i,0,n)idx[i]=0,cmp[i]=-1,g2[i].clear(),gst[i].clear();
	qidx=0; qcmp=0;
	/*mset(idx,0); // NO TEST CASES
	mset(cmp,-1);*/
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}

//decompose range in O(log) subranges
void add(ll x, ll y, ll t){
	//cout<<"add "<<x<<" "<<y<<"\n";
	if(!t)g[x].pb(y); // down
	else g[y].pb(x);  // up
}
ll cnt=0;
struct Rang{
	ll n,t; vector<ll>k;
	Rang(){}
	Rang(ll n, ll t):n(n),t(t),k(2*n+5){}
	void init(vector<ll>a){
		fore(i,0,n){
			k[i]=cnt++;
			k[i+n]=a[i];
		}
		fore(i,1,n){
			add(k[i],k[2*i],t);
			add(k[i],k[2*i+1],t);
		}
	}
	void query(ll l, ll r, ll c){
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)add(c,k[l++],t);
			if(r&1)add(c,k[--r],t);
		}
	}
};
ll vis[MAXN];
void dfs(ll x){
	for(auto y:g2[x])if(!vis[y]){
		vis[y]=1;
		dfs(y);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll N; cin>>N;
		fore(i,0,4*N+5){
			g[i].clear();
		}
		vector<ll>a(2*N);
		vector<vector<ll>>p(N);
		fore(i,0,2*N)cin>>a[i],a[i]--,p[a[i]].pb(i);
		cnt=N;
		Rang rg(2*N,0);
		rg.init(a);
		fore(i,0,N){
			rg.query(p[i][0]+1,p[i][1],i);
		}
		n=cnt;
		scc();
		fore(i,0,n2)vis[i]=0;
		set<ll>real;
		vector<ll>sz(n2);
		fore(i,0,N)real.insert(cmp[i]),sz[cmp[i]]++;
		for(auto i:real)if(!vis[i])dfs(i);
		ll res=0,num=1;
		for(auto i:real)if(!vis[i]){
			res++;
			num=num*sz[i]*2%MOD;
		}
		cout<<res<<" "<<num<<"\n";
	}
	return 0;
}
