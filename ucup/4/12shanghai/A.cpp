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
const ll MAXN=3e4+5;


vv g[MAXN];
ll n;
ll S[MAXN],E[MAXN],D[MAXN],fa[MAXN];
ll cnt=0;
void dfs0(ll x){
	S[x]=cnt++;
	for(auto y:g[x]){
		D[y]=D[x]+1;
		dfs0(y);
	}
	E[x]=cnt;
}
ll dep;
ll QUERIES;
ll ask(ll x, ll k){
	cout<<"? "<<x+1<<" "<<k<<endl;
	ll ret; cin>>ret;
	assert(++QUERIES<=40);
	return ret;
}

ll cant[MAXN],is[MAXN];
ll tot;
void dfs1(ll x){
	cant[x]=is[x];
	for(auto y:g[x]){
		dfs1(y);
		cant[x]+=cant[y];
	}
}
void doit(ll L, ll R, ll in){ // also recalcs cant
	tot=0;
	fore(i,0,n){
		is[i]&=(L<=S[i]&&S[i]<R)==in;
		tot+=is[i];
	}
	dfs1(0);
	assert(tot>0);
}
ll get(){
	ll best=-1,dif=n+5;
	fore(x,0,n){
		ll got=cant[x],comp=tot-got;
		ll cur=abs(comp-got);
		if(cur<dif)dif=cur,best=x;
	}
	return best;
}
int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		QUERIES=0;
		cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			cin>>fa[i]; fa[i]--;
			g[fa[i]].pb(i);
		}
		fa[0]=-1; cnt=0; D[0]=0;
		dfs0(0);
		ll mxd=0;
		fore(i,0,n)mxd=max(mxd,D[i]);
		// cerr<<"mxd "<<mxd<<"\n";
		ll l=-1,r=mxd+1;
		while(r-l>1){
			ll m=(l+r)/2;
			if(ask(0,m))r=m;
			else l=m;
		}
		dep=r;
		fore(i,0,n)is[i]=D[i]==dep;
		ll ini=count(is,is+n,1);
		doit(0,n,1);
		assert(tot==ini);
		while(tot>1){
			ll x=get();
			assert(D[x]<=dep);
			ll k=dep-D[x];
			ll in=ask(x,k);
			doit(S[x],E[x],in);
		}
		assert(tot==1);
		ll res=-1;
		fore(i,0,n)if(is[i])res=i;
		cout<<"! "<<res+1<<endl;
	}
	return 0;
}
