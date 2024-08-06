#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,K=17;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	vector<ii>bag;
	void upd(ll p, ll v){
		bag.pb({p,v});
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
	void reset(){
		for(auto [p,v]:bag)upd(p,-v);
		bag.clear();
	}
};
vector<ll> g[MAXN];
vector<ll>t[MAXN];
ll S[MAXN],E[MAXN],F[K][MAXN],D[MAXN];
ll is[MAXN],we[MAXN];
ll p,tot;
STree st(MAXN);
bool es(ll x){
	ll h=st.query(S[x],E[x]);
	is[x]=h>tot-h;
	// cout<<"es "<<x<<": "<<is[x]<<"\n";
	return is[x];
}
bool leaf(ll x){
	if(x==0)return SZ(t[x])==1;
	return !SZ(t[x]);
}
ll cnt=0;
ll id[MAXN];
void dfs0(ll x, ll pa=-1){
	vector<ll>aux;
	for(auto y:g[x])if(y!=pa)aux.pb(y);
	g[x]=aux;
	for(auto y:g[x])dfs0(y,x);
	if(x&&SZ(g[x])==1)id[x]=id[g[x][0]];
}
void dfs1(ll x){
	S[x]=cnt++;
	for(auto y:t[x])if(y!=F[0][x]){
		F[0][y]=x;
		D[y]=D[x]+we[y];
		dfs1(y);
	}
	E[x]=cnt;
}
void add_parent(ll x, ll fa){
	F[0][x]=fa;
	fore(k,1,K){
		if(F[k-1][x]==-1)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll cuenta(ll x, ll b){
	ll h=st.query(S[x],E[x]);
	ll ret=h;
	if(b)ret=tot-h;
	ret*=we[x];
	// cout<<"cuenta "<<x<<" "<<b<<": "<<h<<" = "<<ret<<"\n";
	return ret;
}
ll father(ll v, ll x){
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)return x;
	}
	return x;
}
ll _p,_res,_tot;
ll res=0;
void upd(ll x){
	// cout<<"upd "<<x<<"\n";
	// cout<<"antes "<<p<<" "<<tot<<" "<<res<<"\n";
	if(!leaf(x)){
		// cout<<"lo hago "<<x<<"\n";
		st.upd(S[x],1);
		tot++;
		ll y=x,d=0;
		for(ll k=K-1;k>=0;k--)if(F[k][y]!=-1&&!is[F[k][y]]){
			d+=D[y]-D[F[k][y]];
			y=F[k][y];
		}
		res+=d+(!is[y])*we[y];
		y=F[0][y];
		res+=D[p]-D[y]-1;
		if(S[p]<=S[x]&&S[x]<E[p]){
			//bajo
			while(p!=x){
				y=father(D[x]-D[p]-1,x);
				if(es(y))p=y;//,cout<<"bajo a "<<p<<"\n";
				else break;
			}	
		}
		else {
			// subo
			while(!es(p)){
				res+=-cuenta(p,1)+cuenta(p,0);
				p=F[0][p];
				// cout<<"subo a "<<p<<"\n";
			}
		}
	}
	res++;
	// cout<<p<<" "<<tot<<" "<<res<<"\n\n";
	t[x].pb(-1); //
	
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)id[i]=i;
	dfs0(0);
	fore(i,0,n)we[id[i]]++;
	fore(i,0,n)if(id[i]==i){
		for(auto j:g[i])t[i].pb(id[j]);
	}
	fore(i,0,n){
		cout<<i<<": ";
		imp(t[i]);
	}
	F[0][0]=-1; D[0]=0;
	dfs1(0);
	fore(i,0,n){
		add_parent(i,F[0][i]);
		tot+=leaf(i);
		st.upd(S[i],leaf(i));
	}
	is[0]=1; p=0;
	while(1){
		ll _p=p;
		for(auto y:t[p])if(y!=F[0][p]){
			if(es(y))p=y;
		}
		if(p==_p)break;
	}
	fore(i,0,n)res+=cuenta(i,es(i));
	st.bag.clear();
	_p=p; _res=res; _tot=tot;
	fore(i,0,q){
		ll m; cin>>m;
		vector<ll>a(m);
		fore(i,0,m)cin>>a[i],a[i]--,a[i]=id[a[i]];
		for(auto x:a)upd(x);
		if(tot&1)cout<<"-1\n";
		else cout<<res<<"\n";
		st.reset();
		ll x=p=_p;
		res=_res; tot=_tot;
		while(!is[x])is[x]=1,x=F[0][x];
		for(auto i:a){
			t[i].pop_back();
		}
	}
	return 0;
}