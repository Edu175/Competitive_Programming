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
const ll MAXN=3e3+5;

struct UF{
	ll n,q; vector<vector<ll>> comp; vector<ll> id;
	void init(ll x){
		q=n=x; id.resize(n); comp.resize(n);
		fore(i,0,n)comp[i]={i},id[i]=i;
	}
	bool join(ll b, ll a){
		a=id[a], b=id[b];
		if(a==b)return 0;
		if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
		for(auto i:comp[a])comp[b].pb(i), id[i]=b;
		comp[a].clear(); q--;
		return 1;
	}
};
ll n;
vector<pair<ll,ll>>g[MAXN];
pair<ll,ll> mat[MAXN];
bool vis[MAXN];

bool match(ll x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto i:g[x]){
		if(mat[i.fst].fst==-1||match(mat[i.fst].fst)){
			mat[i.fst]={x,i.snd};
			return 1;
		}
	}
	return 0;
}
ll is[MAXN];
ll max_matching(){
	fore(i,0,n)mat[i].fst=-1;
	mset(vis,0);
	mset(is,0);
	ll res=0;
	fore(i,0,n)mset(vis,0),res+=(match(i));
	fore(i,0,n)if(mat[i].fst!=-1)is[mat[i].snd]=1;
	return res;
}
int main(){FIN;
	cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)cin>>b[i],b[i]--;
	UF c,d;
	c.init(n),d.init(n);
	fore(i,0,n)c.join(i,a[i]),d.join(i,b[i]);
	fore(i,0,n)g[c.id[i]].pb({d.id[i],i});
	ll res=max_matching();
	cout<<n-res<<"\n";
	fore(i,0,n)if(!is[i])cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
