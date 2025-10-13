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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5;

vector<ll> g[MAXN];
const ll K=19;
ll F[K][MAXN],D[MAXN],S[MAXN],E[MAXN];
vv ord;
void lca_dfs(ll x){
	S[x]=SZ(ord); ord.pb(x);
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
	E[x]=SZ(ord); ord.pb(x);
}
void lca_init(ll n){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

struct BS{
	ll sq,n;
	vector<ll> sum,a;
	BS(ll N):sq(sqrt(N)+.5),n((N+sq-1)/sq*sq),sum(n/sq+3),a(n){}
	void ch(ll p){
		ll bl=p/sq;
		sum[bl]-=a[p];
		a[p]^=1;
		sum[bl]+=a[p];
	}
	ll get(ll l, ll r){
		ll s=l/sq,e=r/sq;
		if(s==e){
			fore(i,l,r)if(a[i])return i;
			return -1;
		}
		fore(i,l,(s+1)*sq)if(a[i])return i;
		fore(i,e*sq,r)if(a[i])return i;
		fore(i,s+1,e)if(sum[i]){
			fore(j,i*sq,(i+1)*sq)if(a[j])return j;
			assert(0);
		}
		return -1;
	}
};

int sq; // array size, sqrt(array size), #queries
struct qu{int l,r,id; ll anc,s,e;};
qu qs[MAXN];
ll a[MAXN];
BS bs(1);
void add(ll i){
	ll x=ord[i];
	bs.ch(a[x]);
}
void remove(ll i){
	add(i);
}
ll get_ans(qu q){
	bs.ch(a[q.anc]);
	ll ret=bs.get(q.s,q.e);
	bs.ch(a[q.anc]);
	return ret;
}
ll ans[MAXN];
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(ll n, ll nq){
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans(q);
    }
}


int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init(n);
	fore(i,0,q){
		ll x,y,s,e; cin>>x>>y>>s>>e; x--,y--,s--;
		if(E[x]>E[y])swap(x,y);
		qs[i].l=E[x];
		qs[i].r=E[y];
		qs[i].anc=lca(x,y);
		qs[i].s=s;
		qs[i].e=e;
		// cout<<x<<","<<y<<": "<<qs[i].anc<<"\n";
	}
	bs=BS(n);
	mos(SZ(ord),q);
	fore(i,0,q){
		ll cur=ans[i];
		if(cur!=-1)cur++;
		cout<<cur<<"\n";
	}
	return 0;
}
