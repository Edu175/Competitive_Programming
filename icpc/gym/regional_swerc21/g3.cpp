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

// I have to direct edges (small -> big)
// and maximize # of paths
// assuming diameter is a path // false, I think *a* diameter is a path
// assuming subtree of 'y node' is rooted there
// 'y node' = child of a diameter node
// i.e. all edges 'go down' or 'go up', counting father edge


// idea: think of tree rooted at center(s) // no, distance is a good heuristic but it actually has nothing to do with max # of paths, max product of # of nodes, etc


ll solve(vector<queue<ll>> a){ // sizes of 'y nodes' subtrees
	ll n=SZ(a);
	ll l=0,r=n-1,sl=0,sr=0,res=0;
	// cout<<"solve "; imp(a)
	while(l<=r){
		// cout<<l<<","<<r<<" "<<sl<<","<<sr<<"\n";
		ll h=(n+sl+sr+1)/2;
		if(sl+l+1<=h){
			if(!SZ(a[l])){l++;continue;}
			ll v=a[l].front();
			res+=(n-1-l+sr)*v,sl+=v;
			a[l].pop();
		// ,cout<<"l +="<<n-1-l+sr<<"\n";
		}
		else if(n-r+sr<=h){
			if(!SZ(a[r])){r--;continue;}
			ll v=a[r].front();
			res+=(r+sl)*v,sr+=v;
			a[r].pop();
		// ,cout<<"r +="<<r+sl<<"\n";
		}
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
	cout<<s+1<<","<<e+1<<" s,e\n";
	imp(p)
	reverse(ALL(p));
	for(auto i:p)dfs1(i,-1);
	ll k=SZ(p),fij=k*(k-1)/2;
	// cout<<fij<<" fij\n";
	fore(x,0,n)fij+=D[x]+1;
	vector<queue<ll>> a;
	cout<<"a: ";
	for(auto x:p){
		queue<ll> q;
		cout<<"{ ";
		for(auto y:g[x])if(!isp[y])q.push(c[y]),cout<<c[y]<<" ";
		a.pb(q);
		cout<<"} ";
	}
	cout<<"\n";
	ll res=solve(a);
	cout<<fij<<" fij\n";
	cout<<res<<" res\n";
	res+=fij;
	cout<<res<<"\n";
	return 0;
}