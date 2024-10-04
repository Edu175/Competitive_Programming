#include "closing.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e15;

vector<ll> d[2];
ll b[MAXN][2];
ll n,k;
vector<ii> g[MAXN];
void dfs(ll x, vector<ll> &d){
	for(auto [y,w]:g[x])if(d[y]==-1){
		d[y]=d[x]+w;
		dfs(y,d);
	}
}
ll disjoint(){
	vector<ll>v;
	fore(i,0,n)v.pb(b[i][0]);
	sort(ALL(v));
	ll ki=0,res=0;
	// imp(v);
	fore(i,0,SZ(v)){
		if(ki+v[i]<=k)res++,ki+=v[i];
	}
	return res;
}
vector<ll>a;
ll dfs1(ll x, ll e, ll fa=-1){
	a.pb(x);
	if(x==e)return 1;
	for(auto [y,w]:g[x])if(y!=fa&&dfs1(y,e,x))return 1;
	a.pop_back();
return 0;
}
vector<vector<ll>>h;
ll m;
void dfs2(ll x, ll fa=-1){
	ll i=SZ(h)-1;
	if((i&&x==a[i-1])||(i<m-1&&x==a[i+1]))return;
	h[i].pb(x);
	for(auto [y,w]:g[x])if(y!=fa)dfs2(y,x);
}
vector<vector<ll>>val;
vector<vector<ii>>con;
bool can(ll c){
	// cout<<"can "<<c<<":\n";
	vector<vector<ll>>dp(m+1,vector<ll>(c+1,INF));
	// fore(s,0,c+1)dp[m][s]=INF;
	dp[m][0]=0;
	for(ll i=m-1;i>=0;i--)fore(s,0,c+1){
		ll &res=dp[i][s];
		// res=INF;
		fore(j,1,SZ(val[i])){
			if(s>=j)res=min(res,val[i][j]+dp[i+1][s-j]);
		}
		// cout<<i<<" "<<s<<": "<<res<<"\n";
	}
	// cout<<dp[0][c]<<"\n\n";
	return dp[0][c]<=k;
}

int max_score(int N, int x, int y, long long K,
              std::vector<int> U, std::vector<int> V, std::vector<int> W)
{
	n=N,k=K;
	fore(i,0,n){
		g[i].clear();
	}
	h.clear();
	val.clear();
	a.clear();
	
	fore(i,0,n-1){
		g[U[i]].pb({V[i],W[i]});
		g[V[i]].pb({U[i],W[i]});
	}
	d[0]=d[1]=vector<ll>(n,-1);
	d[0][x]=0; dfs(x,d[0]);
	d[1][y]=0; dfs(y,d[1]);
	fore(i,0,n){
		auto &x=b[i][0],&y=b[i][1];
		x=d[0][i];
		y=d[1][i];
		if(x>y)swap(x,y);
		y-=x;
	}
	ll res=disjoint();
	dfs1(x,y);
    m=SZ(a);
	fore(i,0,m){
		h.pb({}),dfs2(a[i]);	
		auto &v=h.back();
		ll sz=SZ(v),dif=b[a[i]][1];
		vector<ll>ds;
		for(auto i:v)ds.pb(b[i][0]),assert(b[i][1]==dif);
		sort(ALL(ds));
		// cout<<"("<<sz<<") "; imp(ds); cout<<endl;
		vector<ii>ev[2*sz+5];
		ll sum=0;
		fore(j,0,sz+1){
			ev[j].pb({sum-dif*j,1});
			ev[2*j+1].pb({sum-dif*j,-1});
			if(j<sz)sum+=ds[j];
		}
		vector<ll>va(2*sz+1,INF);
		multiset<ll>st;
		fore(z,0,2*sz+1){
			for(auto [v,de]:ev[z]){
				if(de==-1)st.erase(st.find(v));
				else st.insert(v);
			}
			va[z]=*st.begin()+dif*z;
		}
		// cout<<i<<": "; imp(va); // good samples
		val.pb(va);
		vector<ii>co;
		fore(i,0,SZ(va)){
			ll j=i+1;
			co.pb({va[i],1});
			while(j<SZ(va)-1&&va[j+1]-va[j]<=va[j]-va[j-1]){
				co.back().fst=va[]
			}
		}
    }
    ll l=m,r=2*n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	// cout<<r<<" r\n";
	if(r>=m)res=max(res,r);
	
	
    return res;
}
