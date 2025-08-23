#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll solve(vv a){ // given number of strict descendants in diameter
	ll n=SZ(a);
	ll l=0,r=n-1,sl=0,sr=0,res=0;
	cout<<"solve "; imp(a)
	while(l<=r){
		// cout<<l<<","<<r<<" "<<sl<<","<<sr<<"\n";
		ll h=(n+sl+sr+1)/2;
		if(sl+l+1<=h)res+=(n-1-l+sr)*a[l],sl+=a[l++];
		// ,cout<<"l +="<<n-1-l+sr<<"\n";
		else if(n-r+sr<=h)res+=(r+sl)*a[r],sr+=a[r--];
		// ,cout<<"r +="<<r+sl<<"\n";
		else assert(0);
	}
	return res;
}
const ll MAXN=1e6+5;

vv g[MAXN];

ll d[MAXN],fa[MAXN];
void dfs0(ll x, ll _fa){
	fa[x]=_fa;
	for(auto y:g[x])if(y!=_fa){
		d[y]=d[x]+1;
		dfs0(y,x);
	}
}
ll isp[MAXN],D[MAXN],c[MAXN];
void dfs1(ll x, ll fa){
	c[x]=!isp[x];
	for(auto y:g[x])if(y!=fa&&!isp[y]){
		D[y]=D[x]+1;
		dfs1(y,x);
		c[x]+=c[y];
	}
}
int main(){
	FIN;
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
		g[i].pb(p);
	}
	dfs0(0,-1);
	ll s=max_element(d,d+n)-d;
	dfs0(s,-1);
	ll e=max_element(d,d+n)-d;
	vv p;
	ll x=e;
	while(x!=-1)p.pb(x),isp[x]=1,D[x]=0,x=fa[x];
	imp(p)
	reverse(ALL(p));
	for(auto i:p)dfs1(i,-1);
	ll k=SZ(p),fij=k*(k-1)/2;
	cout<<fij<<" fij\n";
	fore(x,0,n)fij+=D[x]+1;
	vv a;
	for(auto i:p)a.pb(c[i]);
	ll res=solve(a);
	cout<<fij<<" fij\n";
	cout<<res<<" res\n";
	res+=fij;
	cout<<res<<"\n";
	return 0;
}