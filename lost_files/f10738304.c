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
typedef long long ll;
const ll MAXN=1e6+5;

/*vector<ll> comp[MAXN]; ll id[MAXN];
void uf_init(ll n){fore(i,0,n)comp[i]={i},id[i]=i;}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), id[i]=b;
	comp[a].clear();
	return 1;
}*/
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	vector<ll> vis(n*m,0);
	ll res=0;
	vector<ll>dir={-m,-1,m,1};
	uf_init();
	while(q--){
		ll t; cin>>t;
		if(!t)cout<<res<<"\n";
		else{
			ll x,y; cin>>x>>y; x--,y--;
			ll w=x*m+y;
			if(vis[w])continue;
			vis[w]=1;
			res++;
			/*cout<<w<<": ";
			for(auto i:dir)cout<<w+i<<":"<<vis[w+i]<<" ";
			cout<<"\n";*/
			if(x&&vis[w+dir[0]])res-=uf_join(w,w+dir[0]);
			if(y&&vis[w+dir[1]])res-=uf_join(w,w+dir[1]);
			if(x<n-1&&vis[w+dir[2]])res-=uf_join(w,w+dir[2]);
			if(y<m-1&&vis[w+dir[3]])res-=uf_join(w,w+dir[3]);
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
