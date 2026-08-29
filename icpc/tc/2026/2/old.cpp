#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
const int MAXN = 5e5, K=20;
vi g[MAXN];
int tag[MAXN],fat[MAXN],szt[MAXN],inv[MAXN];
vi dst[MAXN];
vi hojas[MAXN];
int calcsz(int x, int f){
	szt[x] =1;
	for(auto [y,w]:g[x])if(y!=f&&tag[y]<0)szt[x] += calcsz(y,x);
	return szt[x];
}
int ccnt = 0;
void cdfs(int x, int f, int sz = -1){
	if(sz<0)sz= calcsz(x,-1);
	for(auto [y,w]:g[x])if(tag[y] <0 && szt[y]*2>=sz){
			szt[x] = 0;
			cdfs(y,f,sz); 
			return;
	}
	tag[x] = ccnt++; fat[x]=f;
	for(auto [y,w]:g[x])if(tag[y]<0)cdfs(y,x);
}
void centroid(){mset(tag,-1);ccnt=0;cdfs(0,-1);}



void dfs(ll u, ll f,const ll &c, ll ds){
	dst[u].pb({c,ds});
	if(SZ(g[u])==1) hojas[c].pb({u,ds});
	
	for(auto [v,w]:g[u])if(v!=f&&tag[v]>=tag[c]){
		dfs(v,u,c,ds+w);
	}
	
}

typedef ll nd;
const ll INF=1e18;
#define oper min
#define NEUT INF
struct STree{
	int n ; vector<nd> t;
	STree(int n): n(n), t(2*n+5,NEUT) {}
	STree() {}
	void init(vi &a){
		sort(ALL(a));
		n=SZ(a);
		t.resize(2*n+5);
		fill(ALL(t),NEUT);
		fore(i,0,n) t[n+i]=a[i].snd;
		for(int i=n-1; i>0; i--) t[i]=oper(t[2*i],t[2*i+1]);
	}
	nd query(int l, int r){
		nd izq=NEUT,der=NEUT;
		for(l+=n,r+=n; l<r; l>>=1,r>>=1){
			if(l&1) izq=oper(izq,t[l++]);
			if(r&1) der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
STree ST[MAXN];

int main(){
	JET
	ll n; cin>>n; ll q; cin>>q;
	fore(i,1,n){
		ll p,w; cin>>p>>w; p--;
		g[i].pb({p,w});
		g[p].pb({i,w});
	}
	centroid();
	fore(i,0,n){
		dfs(i,-1,i,0);
	}
	fore(i,0,n) ST[i].init(hojas[i]);
	
	while(q--){
		ll u,l,r; cin>>u>>l>>r; u--,l--;
		ll rt=INF;
		for(const auto &[c,ds]: dst[u])if(SZ(hojas[c])){
			ll L=lower_bound(ALL(hojas[c]),(ii){l,-INF})-hojas[c].begin();
			ll R=lower_bound(ALL(hojas[c]),(ii){r,-INF})-hojas[c].begin();
			// cout<<c<<"centroid, "<<ds<<"dist al centroid, "<<ST[c].query(L,R)<<"dist a hoja, query de "<<u<<"\n";

			rt=min(rt,ds+ST[c].query(L,R));
		}
		cout<<rt<<"\n";
	}
	return 0;
}