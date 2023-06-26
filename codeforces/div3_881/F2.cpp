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
typedef int ll;
typedef pair<ll,ll> ii;

struct node{
	ll sum,pre,suf,all;
	ll sum1,pre1,suf1;
	node(ll a):sum(a),pre(a),suf(a),all(a),sum1(a),pre1(a),suf1(a){}
	node(){}
};
node oper(node a, node b){ // a left, b right
	node p;
	p.all=a.all+b.all;
	p.sum=max({a.sum,b.sum,a.suf+b.pre});
	p.pre=max(a.pre,a.all+b.pre);
	p.suf=max(b.suf,a.suf+b.all);
	
	p.sum1=min({a.sum1,b.sum1,a.suf1+b.pre1});
	p.pre1=min(a.pre1,a.all+b.pre1);
	p.suf1=min(b.suf1,a.suf1+b.all);
	return p;
}
node rev(node a){
	swap(a.pre,a.suf);
	swap(a.pre1,a.suf1);
	return a;
}
node NEUT=node(0);
struct qu{
	ll u,v,k;
	qu(ll u, ll v, ll k):u(u),v(v),k(k){}
	qu(){}
};
const ll MAXN=2e5,K=18;
vector<ii>g[MAXN]; ll n;
ll F[K][1ll<<K],D[MAXN];
node V[K][1ll<<K];
void lca_dfs(ll x){
	for(auto i:g[x])if(i.fst!=F[0][x]){
		ll y=i.fst;
		D[y]=D[x]+1; F[0][y]=x; V[0][y]=i.snd;
		lca_dfs(y);
	}
}
void lca_init(){
	F[0][0]=-1; D[0]=0;
	lca_dfs(0);
	fore(k,1,K)fore(i,0,n){
		if(F[k-1][i]<0)continue;
		F[k][i]=F[k-1][F[k-1][i]];
		V[k][i]=oper(V[k-1][i],V[k-1][F[k-1][i]]);
	}
}
pair<ll,node> query(ll x, ll y){ // {lca,ans}
	node l=NEUT,r=NEUT;
	cout<<x<<" "<<y<<":\n";
	if(D[x]>D[y]){
		for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
			l=oper(l,V[k][x]); x=F[k][x];
			cout<<x<<","<<F[k][x]<<"\n";
		}
	}
	else {
		for(ll k=K-1;k>=0;k--)if(D[y]-(1ll<<k)>=D[x]){
			r=oper(r,V[k][y]); y=F[k][y];
			cout<<y<<","<<F[k][y]<<"\n";
		}
	}
	if(x==y)return {x,oper(l,rev(r))};
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		l=oper(l,V[k][x]); x=F[k][x];
		r=oper(r,V[k][y]); y=F[k][y];
	}
	l=oper(l,V[0][x]); x=F[0][x];
	r=oper(r,V[0][y]); y=F[0][y];
	return {x,oper(l,rev(r))};
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>q;
		vector<qu> qs;
		ll n=0;
		fore(i,0,q){
			char ty; cin>>ty;
			if(ty=='+'){
				ll p,w; cin>>p>>w; p--;
				g[p].pb({n,w});
				g[n].pb({p,w});
				n++;
			}
			else {
				ll u,v,k; cin>>u>>v>>k; u--,v--;
				qs.pb(qu(u,v,k));
			}
		}
		lca_init();
		fore(i,0,SZ(qs)){
			ll u=qs[i].u,v=qs[i].v,k=qs[i].k;
			ll r=query(u,v).snd.sum;
			ll l=query(u,v).snd.sum1;
			if(l<=k&&k<=r)cout<<"YES\n";
			else cout<<"NO\n";
		}
		fore(i,0,n){
			g[i].clear();
		}
	}
	return 0;
}
