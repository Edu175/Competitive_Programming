#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MOD=1e9+7;

vector<pair<ll,ii>>ed;
vector<ll> cmp[MAXN]; ll id[MAXN];
void uf_init(){fore(i,0,MAXN)cmp[i]={i},id[i]=i;}
bool uf_join(ll a, ll b){
	a=id[a],b=id[b];
	if(a==b)return 0;
	if(SZ(cmp[a])<SZ(cmp[b]))swap(a,b); //b --> a
	for(auto i:cmp[b]){
		cmp[a].pb(i);
		id[i]=a;
	}
	cmp[b].clear();
	return 1;
}

int main(){FIN;
	uf_init();
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({w,{u,v}});
	}
	ll res=0;
	sort(ALL(ed));
	for(auto i:ed){
		ll a=i.snd.fst,b=i.snd.snd,w=i.fst;
		res=(res+SZ(cmp[id[a]])*SZ(cmp[id[b]])%MOD*w)%MOD;
		uf_join(a,b);
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
