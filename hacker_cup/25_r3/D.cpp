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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
vector<ll> divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=int(i);j<MAXN;j+=int(i))divs[j].pb((int)i);
}
int mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=int(i+i);j<MAXN;j+=(int)i)mu[j]-=mu[i];
}
vv g[MAXN];
ll P[MAXN],D[MAXN];
vv ord;
vv nod[MAXN];
void dfs1(ll x, ll fa){
    P[x]=SZ(ord);
    ord.pb(x);
	for(auto d:divs[x+1])nod[d].pb(x);
    // S[x]=cnt++;
    for(auto y:g[x])if(y!=fa){
        D[y]=D[x]+1;
        dfs1(y,x);
        ord.pb(x);
    }
    // E[x]=cnt;
}
ll oper(ll i, ll j){return D[i]<D[j]?i:j;}
const ll K=18;
int st[K][1<<K];
void st_init(vv a){
    ll n=SZ(a);
    fore(i,0,n)st[0][i]=int(a[i]);
    fore(k,1,K)fore(i,0,n-(1<<k)+1){
        st[k][i]=(int)oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
    }
}
int st_query(int s, int e){
    int k=__lg(e-s);
    return (int)oper(st[k][s],st[k][e-(1<<k)]);
}
 
ll lca(ll x, ll y){
    ll l=P[x],r=P[y];
    if(l>r)swap(l,r);
    ll p=st_query(int(l),int(r+1));
    if(x==y)assert(p==x);
    return p;
}
vv t[MAXN]; // virtual tree, t[ancestor]={descendant_i}
void agr(ll x, ll y){if(y!=-1)t[x].pb(y);}

ll is[MAXN];
ll m,tot;
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii dfs(ll x){ // res,cant
	ii res={0,is[x]};
	for(auto y:t[x]){
		auto got=dfs(y);
		res=res+got;
		ll w=D[y]-D[x];
		ll c=got.snd;
		res.fst+=c*(tot-c)*w;
	}
	return res;
}
ll virtu(vv v){
    stack<ll>s; s.push(v[0]); ll ult=-1,p;
	auto vacia=[&](bool fg){ // adds edges between removed
		while(SZ(s)&&(fg||lca(s.top(),p)!=s.top())){
			agr(s.top(),ult);
			ult=s.top(); s.pop();
		}
	};
	vv vi; // virtual nodes and possibly normal
    fore(i,1,SZ(v)){
		ll x=v[i]; p=lca(s.top(),x);
		vi.pb(p); vacia(0);
		if(s.empty()||p!=s.top())s.push(p);
		agr(p,ult); ult=-1;
		if(p!=x)s.push(x);
	}
	vacia(1);
	ll rt=ult; // root is last popped
	// do stuff
	// remember to reset t with v and vi
	tot=SZ(v);
	for(auto i:v)is[i]=1;
	ii res=dfs(rt);
	assert(res.snd==tot);
	for(auto ve:{v,vi})for(auto i:ve)t[i].clear();
	for(auto i:v)is[i]=0;
	return res.fst;
}

int main(){FIN;
	divisores();
	mobius();
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		// cout<<"\n";
		ll n; cin>>n;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		D[0]=0; ord.clear();
		dfs1(0,-1);
		st_init(ord);
		vv val(n+1);
		fore(_m,1,n+1){
			m=_m;
			ll cur=virtu(nod[m]);
			val[m]=cur;
		}
		auto dis=[&](ll i, ll j){return D[i]+D[j]-2*D[lca(i,j)];};
		// fore(m,1,n+1){
		// 	ll res=0;
		// 	fore(u,0,n)if((u+1)%m==0)fore(v,u+1,n)if((v+1)%m==0){
		// 		res+=dis(u,v);
		// 	}
		// 	// cout<<m<<": "<<res<<"\n";
		// 	assert(res==val[m]);
		// }
		// vv ans()
		for(ll i=n;i>0;i--){
			for(ll j=2*i,k=2;j<=n;j+=i,k++)val[i]-=val[j];
		}
		fore(i,1,n+1)cout<<val[i]<<" ";;cout<<"\n";
		// if(n<=1005){
		// 	vv deb(n+1);
		// 	fore(u,0,n)fore(v,u+1,n)deb[gcd(u+1,v+1)]+=dis(u,v);
		// 	assert(deb==val);
		// }
		// cout<<endl;
		
		fore(i,0,n+1){
			g[i].clear();
			nod[i].clear();
		}
	}
	return 0;
}
