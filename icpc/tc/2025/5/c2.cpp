#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=1e6+5;

vv g[MAXN];
ll lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
ll st[MAXN],po=0;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st[po++]=u; cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		ll x;
		do{x=st[--po];cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(ll n){
	fore(i,0,n)idx[i]=0,cmp[i]=-1;
	qidx=0; qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
	assert(!po);
}


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		// fore(i,0,n){
		// 	g[i].clear();
		// }
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
		}
		scc(n);
		// cout<<n<<" "<<qcmp<<" n qcmp"<<endl;
		if(qcmp==1){
			cout<<"No\n";
			fore(i,0,n){
				g[i].clear();
			}
			continue;
		}
		vv outd(n);
		fore(x,0,n)for(auto y:g[x]){
			ll u=cmp[x],v=cmp[y];
			if(u!=v)outd[u]++;
		}
		// vector<vv> h(n);
		// fore(i,0,n)h[cmp[i]].pb(i);
		ll c=-1;
		fore(i,0,qcmp)if(!outd[i])c=i;
		assert(c!=-1);
		
		vv is(n);
		fore(i,0,n)if(cmp[i]==c)is[i]=1;
		
		vv wh[2];
		fore(i,0,n)wh[!is[i]].pb(i);
		assert(SZ(wh[0])!=n);
		cout<<"Yes\n";
		cout<<SZ(wh[0])<<" "<<SZ(wh[1])<<"\n";
		for(auto i:wh[0])cout<<i+1<<" ";;cout<<"\n";
		for(auto i:wh[1])cout<<i+1<<" ";;cout<<"\n";
		fore(i,0,n){
			g[i].clear();
		}
	}
	return 0;
}

