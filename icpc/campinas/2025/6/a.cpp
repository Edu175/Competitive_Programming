#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vv g[MAXN];
ll n;
ll c[MAXN],ch[MAXN],fa[MAXN];

void dfs1(ll x){
	vv v;
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs1(y);
		v.pb(c[y]);
	}
	sort(ALL(v)); reverse(ALL(v));
	c[x]=1;
	// cout<<"dfs1 "<<x<<": ";
	// for(auto i:v)cout<<i<<" ";;cout<<"\n";
	fore(i,0,SZ(v))c[x]=max(c[x],i+1+v[i]);
}
ll tot[MAXN];
void dfs2(ll x){
	vector<ii>val;
	if(fa[x]!=-1)val.pb({ch[x],fa[x]});
	for(auto y:g[x])if(y!=fa[x])val.pb({c[y],y});
	sort(ALL(val)); reverse(ALL(val));
	ll m=SZ(val),mx=1;
	fore(i,0,m){
		ll y=val[i].snd;
		if(y!=fa[x])ch[y]=mx;
		mx=max(mx,i+1+val[i].fst);
	}
	mx=1;
	for(ll i=m-1;i>=0;i--){
		ll y=val[i].snd;
		if(y!=fa[x])ch[y]=max(ch[y],mx);
		mx=max(mx,i+val[i].fst);
	}
	for(auto y:g[x])if(y!=fa[x])dfs2(y);
	tot[x]=1;
	fore(i,0,m)tot[x]=max(tot[x],i+1+val[i].fst);
}



int main(){
	JET
	cin>>n;
	fore(i,0,n){
		ll k; cin>>k;
		fore(_,0,k){
			ll x; cin>>x;
			g[i].pb(x);
		}
	}
	fa[0]=-1;
	dfs1(0);
	dfs2(0);
	fore(i,0,n){
		// cout<<i<<": "<<c[i]<<" "<<ch[i]<<"\n";
	}
	ll res=tot[0];
	fore(i,0,n)res=min(res,tot[i]);
	cout<<res-1<<"\n";
	return 0;
}
/*

dfs1 1: 
dfs1 3: 
dfs1 2: 1 
dfs1 0: 1 2 
0: 4 0
1: 1 3
2: 2 2
3: 1 3
4


*/