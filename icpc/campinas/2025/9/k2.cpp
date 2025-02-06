#include <bits/stdc++.h>
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
const ll MAXN=1005;
ll g[MAXN][MAXN];
ll n;
ll cnt=2;
bitset<MAXN> vis,vis2;
void operator+=(ii &a, const ii &b){
	a.fst+=b.fst;
	a.snd+=b.snd;
}
set<ll> ncl;
ii dfs(ll i){ //{#nodos,#aristas}
	vis[i]=1;
	ii r={1,0};
	ncl.insert(i);
	fore(j,0,n){
		if(g[i][j]==1){
			r.snd++; 
			if(!vis[j])r+=dfs(j);
		}
	}
	return r;
}
vv rec;
ll pos[MAXN];
bool cicl=false;
void dfsc(ll i, ll ant){
	vis2[i]=1;
	pos[i]=SZ(rec);
	rec.pb(i);
	fore(j,0,n){
		if(g[i][j]==1){
			if(!vis2[j]) dfsc(j,i);
			else if(j!=ant){
				rec.pb(j);
				cicl=true;
				for(ll k=SZ(rec)-2;k>=pos[j];k--){
					g[rec[k]][rec[k+1]]=cnt;
					g[rec[k+1]][rec[k]]=cnt++;
					rec.pop_back();
					ncl.erase(rec[k]);
				}
				rec.pop_back();
			}
		}
		if(cicl) return;
	}
	rec.pop_back();
}
void dfsl(ll i){
	fore(j,0,n){
		if(g[i][j]==1){ 
			g[i][j]=cnt;
			g[j][i]=cnt++;
			dfsl(j);
		}
	}
}
int main(){
	JET
	ll m; cin>>n>>m;
	mset(g,0);
	fore(i,0,m){
		ll x,y; cin>>x>>y;
		x--;y--;
		g[y][x]=1;
		g[x][y]=1;
	}
	if(m>n){cout<<"-1\n"; return 0;}
	fore(i,0,n)if(!vis[i]){
		ii x=dfs(i);
		x.snd/=2;
		if(x.fst<x.snd){cout<<"-1\n"; return 0;}
		if(x.fst==x.snd){
			cicl=false;
			dfsc(i,-1);
		}
		for(auto j: ncl){
			dfsl(j);
		}
		ncl.clear();
	}
	fore(i,0,n)fore(j,0,n){
		if(!g[i][j])g[i][j]=cnt++;
	}
	fore(i,0,n){fore(j,0,n)cout<<g[i][j]<<" ";;cout<<"\n";}
	return 0;
}