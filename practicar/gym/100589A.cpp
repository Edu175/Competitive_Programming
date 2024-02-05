#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ll> g[MAXN];

vector<ll>ord;
ll d[MAXN],S[MAXN],E[MAXN],cd[MAXN];

void dfs1(ll x){
	S[x]=SZ(ord);
	ord.pb(x);
	for(auto y:g[x]){
		d[y]=d[x]+1;
		dfs1(y);
	}
	E[x]=SZ(ord);
}

const ll B=316;
vector<ll>esp;
ll c[MAXN/B][MAXN];
ll add[MAXN/B],p[MAXN];

void dfs2(ll x, ll w){
	if(d[x]==esp[w])c[w][x]++;
	for(auto y:g[x])dfs2(y,w),c[w][x]+=c[w][y];
}

struct BL{
	ll sq,n; vector<ll>a,sum;
	BL(ll nn):sq(sqrt(nn)),n((nn+sq-1)/sq*sq),a(nn),sum(n/sq){}
	void upd(ll p, ll v){
		sum[p/sq]+=v;
		a[p]+=v;
	}
	ll query(ll l, ll r){
		ll res=0;
		if(l/sq==r/sq){
			fore(i,l,r)res+=a[i];
			return res;
		}
		fore(i,l,(l+sq-1)/sq*sq)res+=a[i];
		fore(i,r/sq*sq,r)res+=a[i];
		fore(i,(l+sq-1)/sq,r/sq)res+=sum[i];
		return res;
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	dfs1(0);
	//B=sqrt(n);
	vector<ll> pos[n];
	fore(i,0,n)cd[d[i]]++,pos[d[i]].pb(i);
	mset(p,-1);
	fore(i,0,n)if(cd[i]>=B){p[i]=SZ(esp);esp.pb(i);}
	fore(i,0,SZ(esp))dfs2(0,i);
	BL bl(n);
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll l,y; cin>>l>>y;
			if(p[l]!=-1)add[p[l]]+=y;
			else for(auto x:pos[l])bl.upd(S[x],y);
		}
		else {
			ll x; cin>>x; x--;
			ll res=0;
			fore(i,0,SZ(esp))res+=c[i][x]*add[i];
			res+=bl.query(S[x],E[x]);
			cout<<res<<"\n";
		}
	}
	return 0;
}
