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
const ll MAXN=2e5+5;


#define BLOCKSZ sqrt(n)+5
struct BH{
	//upd O(1), query O(sqrt(n)), memory O(nsqrt(n)))
	ll n,r,q; vector<vector<int>>h; vector<ll>a,sz;
	//r=block size, q=number of blocks
	BH(ll n):n(n),r(BLOCKSZ),q((n+r-1)/r),h(q,vector<int>(n+5)),a(n),sz(q,r){
		if(n%r)sz[q-1]=n%r;
		//fore(i,0,n)sz[i/r]++;
		fore(i,0,q)h[i][0]=sz[i];
	}
	BH(){}
	void upd(ll p, ll v){ //v<n+5
		if(a[p]==n)return;
		ll bp=p/r;
		h[bp][a[p]]--;
		a[p]=v;
		h[bp][a[p]]++;
	}
	ll query(ll x){ //whatever
		ll bp=-1;
		fore(i,0,q)if(h[i][n]+h[i][x]<sz[i]){
			bp=i;
			break;
		}
		if(bp==-1)return -1;
		fore(i,0,r){
			ll pos=r*bp+i;
			if(a[pos]!=n&&a[pos]!=x)return pos;
		}
		assert(0);//no llega
	}
};
BH h;

vector<ll> comp[MAXN]; ll id[MAXN],av[MAXN];

void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
		h.upd(i,i);
		av[i]=1;
	}
}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), id[i]=b,h.upd(i,b);
	av[b]+=av[a];
	av[a]=0;
	comp[a].clear();
	return 1;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		h=BH(n);
		uf_init(n);
		vector<ll>a(n),p(n);
		fore(i,0,n){
			cin>>a[i]; a[i]--;
			p[a[i]]=i;
			uf_join(i,a[i]);
		}
		vector<ll>vis(n);
		ll q=0;
		fore(i,0,n){
			if(vis[i])continue;
			q++;
			for(ll x=i;!vis[x];x=a[x])vis[x]=1;
		}
		fore(i,0,n){
			//if(q==1)break;
			ll x=h.query(id[i]);
			//assert((x==-1)<=(q==1));
			if(x==-1)break;
			if(a[i]<x&&n-1-i>=q-1&&av[id[i]]>1)x=a[i];
			else q--;
			//cout<<i<<" "<<x<<"\n";
			uf_join(i,x);
			h.upd(x,n);
			av[id[i]]--;
			ll j=p[x];
			swap(a[i],a[j]);
			swap(p[a[i]],p[a[j]]);
		}
		//cout<<q<<endl;
		//assert(q<=1);
		for(auto i:a)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
