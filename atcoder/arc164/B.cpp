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
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

vector<ll>g[MAXN];
ll c[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	fore(i,0,n)cin>>c[i];
	vector<ii> e[2];
	fore(i,0,m)e[c[ed[i].fst]^c[ed[i].snd]].pb(ed[i]);
	uf_init();
	for(auto i:e[1])uf_join(i.fst,i.snd);
	ll flag=0;
	for(auto i:e[0])if(uf_find(i.fst)==uf_find(i.snd))flag=1;
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}
