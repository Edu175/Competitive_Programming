#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=2e5+5;

vector<ii> g[MAXN];

ll S[MAXN],E[MAXN],cnt=0;
ll val[MAXN],down[MAXN];
vv tmp;
void dfs0(ll x, ll fa){
	S[x]=cnt++;
	for(auto [y,i]:g[x])if(fa!=y){
		val[y]=tmp[i];
		down[i]=y;
		dfs0(y,x);
	}
	E[x]=cnt;
}


ll cant=0;
vv vals,nod;
ll is[MAXN],c[MAXN],esta[MAXN];
ll wh[MAXN];
vv hist[MAXN]; // cleared
ll fij[MAXN],m;
void dfs1(ll x, ll fa){
	fij[x]=cant;
	// cout<<"dfs1 "<<x<<": "<<cant<<"\n";
	// fore(i,0,m)cout<<c[i]<<" ";;cout<<"\n";
	for(auto [y,kerjt]:g[x])if(y!=fa){
		ll v=val[y];
		c[v]++; cant+=!is[v]&&c[v]==1;
		dfs1(y,x);
		c[v]--; cant-=!is[v]&&c[v]==0;
	}
	if(esta[x]){
		for(auto v:vals)hist[x].pb(c[v]);
	}
}

ll ccnt=0,ori[MAXN],nl[MAXN];
void cache(ll x, ll fa){
	ori[cnt]=x;
	nl[x]=ccnt++;
	for(auto [y,ghfhg]:g[x])if(y!=fa)cache(y,x);
}

const ll B=1500;
int main(){
	JET
	ll n,q; cin>>n>>m>>q;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--,w--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		tmp.pb(w);
	}
	cache(0,-1);
	vector<pair<ll,ii>>ed;
	fore(x,0,n){
		for(auto [y,w]:g[x])ed.pb({nl[x],{nl[y],w}});
		g[x].clear();
	}
	for(auto [x,par]:ed)g[x].pb(par);
	dfs0(0,-1);
	vector<pair<char,ii>>bag;
	while(q--){
		char ty; cin>>ty;
		if(ty=='Z'){
			ll x; cin>>x; x--; x=nl[x];
			bag.pb({'Q',{x,-1}});
		}
		else {
			ll i,c; cin>>i>>c; i--,c--;
			bag.pb({'U',{down[i],c}});
		}
		if(SZ(bag)==B||!q){
			// cout<<"BAG\n";
			vv _vals,_nod;
			for(auto [ty,snd]:bag){
				auto [x,v]=snd;
				if(ty=='U')_vals.pb(val[x]),_vals.pb(v);
				else _nod.pb(x);
			}
			auto put=[&](vv &u, vv &v){
				sort(ALL(u));
				for(auto i:u)if(!SZ(v)||i!=v.back())v.pb(i);
			};
			put(_vals,vals);
			put(_nod,nod);
			
			// cout<<"vals: ";for(auto i:vals)cout<<i<<" ";;cout<<"\n";
			// cout<<"nod: ";for(auto i:nod)cout<<i<<" ";;cout<<"\n";
			for(auto i:vals)is[i]=1;
			// cout<<"is: "; fore(i,0,m)cout<<is[i]<<" ";;cout<<"\n";
			for(auto i:nod)esta[i]=1;
			
			fore(i,0,m)c[i]=0;
			fore(i,0,n)fij[i]=0;
			fore(i,0,SZ(vals))wh[vals[i]]=i;
			cant=0;
			
			dfs1(0,-1);
			
			
			for(auto [ty,snd]:bag){
				auto [x,v]=snd;
				if(ty=='U'){
					for(auto y:nod)if(S[x]<=S[y]&&S[y]<E[x]){
						hist[y][wh[val[x]]]--;
						hist[y][wh[v]]++;
					}
					val[x]=v;
					// cout<<"upd "<<x<<" "<<v<<"\n";
				}
				else {
					// cout<<"query "<<x<<": "<<fij[x]<<": ";
					ll res=fij[x];
					for(auto num:hist[x])res+=num>0;
					cout<<res<<"\n";
				}
			}
			for(auto i:nod)hist[i].clear();
			for(auto i:vals)is[i]=0;
			for(auto i:nod)esta[i]=0;
			fore(i,0,SZ(vals))wh[vals[i]]=0; // unesecary
			vals.clear();
			nod.clear();
			bag.clear();
		}
	}
	return 0;
}

/*

BAG
vals: 
nod: 1 2 3 
is: 0 0 0 0 
dfs1 0: 0
0 0 0 0 
dfs1 1: 1
0 0 1 0 
dfs1 7: 2
0 0 1 1 
dfs1 5: 1
1 0 0 0 
dfs1 3: 2
1 1 0 0 
dfs1 2: 3
1 1 1 0 
dfs1 4: 2
1 2 0 0 
dfs1 6: 2
2 1 0 0 
query 1: 1: 1
query 2: 3: 3
query 3: 2: 2
BAG
vals: 
nod: 4 5 6 
is: 0 0 0 0 
dfs1 0: 0
0 0 0 0 
dfs1 1: 1
0 0 1 0 
dfs1 7: 2
0 0 1 1 
dfs1 5: 1
1 0 0 0 
dfs1 3: 2
1 1 0 0 
dfs1 2: 3
1 1 1 0 
dfs1 4: 2
1 2 0 0 
dfs1 6: 2
2 1 0 0 
query 4: 2: 2
query 5: 1: 1
query 6: 2: 2
BAG
vals: 0 1 2 3 
nod: 7 
is: 1 1 1 1 
dfs1 0: 0
0 0 0 0 
dfs1 1: 0
0 0 1 0 
dfs1 7: 0
0 0 1 1 
dfs1 5: 0
1 0 0 0 
dfs1 3: 0
1 1 0 0 
dfs1 2: 0
1 1 1 0 
dfs1 4: 0
1 2 0 0 
dfs1 6: 0
2 1 0 0 
query 7: 0: 2
upd 5 3
upd 3 2
BAG
vals: 0 2 3 
nod: 1 
is: 1 0 1 1 
dfs1 0: 0
0 0 0 0 
dfs1 1: 0
0 0 1 0 
dfs1 7: 0
0 0 1 1 
dfs1 5: 0
1 0 0 0 
dfs1 3: 1
1 1 0 0 
dfs1 2: 1
1 1 1 0 
dfs1 4: 1
1 2 0 0 
dfs1 6: 1
2 1 0 0 
upd 6 3
upd 7 2
query 1: 0: 1
BAG
vals: 
nod: 2 3 4 
is: 0 0 0 0 
dfs1 0: 0
0 0 0 0 
dfs1 1: 1
0 0 1 0 
dfs1 7: 2
0 0 1 1 
dfs1 5: 1
1 0 0 0 
dfs1 3: 2
1 1 0 0 
dfs1 2: 3
1 1 1 0 
dfs1 4: 2
1 2 0 0 
dfs1 6: 2
2 1 0 0 


aca ya da mal

query 2: 3: 3
query 3: 2: 2
query 4: 2: 2

deberia ser 
2
2
3


BAG
vals: 
nod: 5 6 7 
is: 0 0 0 0 
query 5: 1: 1
query 6: 2: 2
query 7: 2: 2
BAG
vals: 1 3 
nod: 6 
is: 0 1 0 1 
upd 3 3
query 6: 1: 2



*/