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
typedef ll node;
/*node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};*/
const ll MAXN=4e5+5;
vv g[MAXN];
ll cnt=0;
ll S[MAXN],E[MAXN];
void dfs(ll x, ll fa){
	S[x]=cnt++;
	for(auto y:g[x])if(y!=fa)dfs(y,x);
	E[x]=cnt;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		cnt=0;
		vv vals;
		vv nod[n];
		fore(i,0,n){
			ll c; cin>>c; c--;
			vals.pb(c);
			nod[c].pb(i);
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		sort(ALL(vals));
		dfs(0,-1);
		ll res=-1;
		fore(i,0,SZ(vals)-1){
			ll me=vals[i],he=vals[i+1];
			if(me==he)continue;
			ll mn=n+1,mx=-1;
			for(auto i:nod[he]){
				mn=min(mn,S[i]);
				mx=max(mx,S[i]);
			}
			for(auto x:nod[me]){
				if(mn<S[x]||mx>=E[x])res=x;
			}
		}
		cout<<res+1<<"\n";
	}
	return 0;
}
