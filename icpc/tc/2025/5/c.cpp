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
typedef long long ll;
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

void limpiar(int n){
	fore(i,0,n) g[i].clear();
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,m){
			ll x,y; cin>>x>>y;
			x--,y--;
			g[x].pb(y);
		}
		scc(n);
		if (qcmp == 1){
			cout<<"No\n";
			limpiar(n);
			continue;
		}
		vv outd(qcmp,0);
		fore(i,0,n){
			ll act = cmp[i];
			for(auto x:g[i]) if(cmp[x]!=act) outd[act]++;
		}
		ll buena = -1;
		// cout<<"cantidad de componentes conexas: "<<qcmp<<endl;
		fore(i,0,qcmp){
			if(outd[i] == 0){
				buena = i;
				break;
			}
		}
		assert(buena>=0);
		vv ar,ab;
		fore(i,0,n){
			if(cmp[i] == buena) ar.pb(i);
			else ab.pb(i);
		}
		cout<<"Yes\n";
		cout<<SZ(ar)<<" "<<SZ(ab)<<"\n";
		for(auto x:ar) cout<<x+1<<" ";
		cout<<"\n";
		for(auto x:ab) cout<<x+1<<" ";
		cout<<"\n";
		limpiar(n);
	}
	return 0;
}

