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
const ll MAXN=1e5+5;

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

//=================================MST========================================
ll k, is[MAXN];
struct comp{
	vector<ll>v;
	ll q;
	comp(ll x):v(1,x),q(is[x]){}
	comp(){}
};
comp cmp[MAXN]; ll id[MAXN];
void uf_init(){
	fore(i,0,MAXN)id[i]=i,cmp[i]=comp(i);
}
bool uf_join(ll a, ll b){
	a=id[a],b=id[b];
	if(a==b)return 0;
	if(SZ(cmp[b].v)>SZ(cmp[a].v))swap(a,b);
	cmp[a].q+=cmp[b].q;
	for(auto i:cmp[b].v)cmp[a].v.pb(i),id[i]=a;
	cmp[b].v.clear(),cmp[b].q=0;
	return 1;
}
vector<pair<ll,ii>>es;
vector<ii>g[MAXN]; 	// MST
ll r;
void kruskal(){
	uf_init();	
	sort(ALL(es));
	for(auto i:es){
		ll a=i.snd.fst,b=i.snd.snd;
		if(uf_join(a,b))g[a].pb({b,i.fst}),g[b].pb({a,i.fst});
		if(cmp[id[a]].q==k)break;
	}
}
//==========================================================================

ll combine(ll a, ll b){
	//combine subtree a and b
	return max(a,b);
}
ll lup(ll x, ll w){// add edge
	//climb a level in tree
	return max(x,w);
}
#define NEUT 0
ll h[MAXN],ch[MAXN]; //hijos, complement hijos
vector<ll>pre[MAXN],suf[MAXN];//	[0,i)  ,  [i,n)
ll f[MAXN];
void subtree(ll x){
	for(auto i:g[x]){
		ll y=i.fst,w=i.snd;
		//cout<<y<<" continue\n";
		if(y==f[x])continue;
		//cout<<y<<" mentira\n";
		f[y]=x;
		subtree(y);
		h[x]=combine(h[x],lup(h[y],w));
		//cout<<"h "<<x<<": "<<h[x]<<"\n";
	}
}
void father_subtree(ll x){
	fore(i,0,SZ(g[x])){
		ll y=g[x][i].fst,w=g[x][i].snd;
		if(y==f[x])continue;
		ch[y]=combine(combine(pre[x][i],suf[x][i+1]),ch[x]);
		ch[y]=lup(ch[y],w);
		//cout<<"ch "<<y<<": "<<ch[y]<<"\n";
		father_subtree(y);
	}
}
void rerooting(ll n){
	fore(i,0,n){// clear if testcases
		h[i]=NEUT, ch[i]=NEUT; // MUST
		pre[i].clear();
		suf[i].clear();
		f[i]=-1;
	}
	subtree(r); //from root
	fore(x,0,n){
		suf[x].resize(SZ(g[x])+1,NEUT);
		pre[x].resize(SZ(g[x])+1,NEUT);
		fore(i,1,SZ(g[x])+1){			
			ll y=g[x][i-1].fst,w=g[x][i-1].snd;
			if(y==f[x])pre[x][i]=pre[x][i-1];
			else pre[x][i]=combine(pre[x][i-1],lup(h[y],w));
		}
		for(ll i=SZ(g[x])-1;i>=0;i--){
			ll y=g[x][i].fst,w=g[x][i].snd;
			if(y==f[x])suf[x][i]=suf[x][i+1];
			else suf[x][i]=combine(suf[x][i+1],lup(h[y],w));
		}
	}
	father_subtree(r);
	// stores subtree in h and complement in ch
}
int main(){FIN;
	ll n,m; cin>>n>>m>>k;
	ll a[k];
	fore(i,0,k){
		cin>>a[i], a[i]--;
		is[a[i]]=1;
	}
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		es.pb({w,{u,v}});
	}
	kruskal();
	fore(i,0,n)if(SZ(g[i])){
		r=i;
		break;
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		for(auto j:g[i])cout<<j.fst<<","<<j.snd<<" ";
		cout<<"\n";
	}*/
	rerooting(n);
	fore(i,0,k)cout<<combine(h[a[i]],ch[a[i]])<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
