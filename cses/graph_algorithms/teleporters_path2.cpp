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
vector<ll> in[MAXN],out[MAXN];
vector<ii>ed;
/*
wrong, requires specific ordering of ca and cb
specifically, sort them in such a way that if comp(a)==comp(b) then pos(a)=pos(b), then next of edge ca[i] is edge cb[(i+1)%SZ(cb)]
note: requires SZ(a)==SZ(b), i.e. eulerian graph
note: trival case SZ(ca)=SZ(cb)=2, and much simpler
strictly worse than typical algorithm
extra log factor (plus union-find factor)
*/
int main(){FIN;
	uf_init();
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	ed.pb({n-1,0});
	m++;
	fore(i,0,m){
		auto [u,v]=ed[i];
		in[v].pb(i);
		out[u].pb(i);
	}
	vector<ll>to(m,-1);
	fore(x,0,n){
		vector<ll> &ca=in[x], &cb=out[x];
		for(auto a:ca)if(SZ(cb)){
			if(SZ(cb)==1)to[a]=cb.back();
			else {
				auto b1=cb.back(); cb.pop_back();
				auto b2=cb.back(); cb.pop_back();
				if(uf_find(a)!=uf_find(b1))to[a]=b1,uf_join(a,b1),cb.pb(b2);
				else to[a]=b2,uf_join(a,b2),cb.pb(b1);
			}
		}
	}
	imp(to);
	cout<<endl;
	ll s=to[m-1];
	vector<ll>p;
	while(s!=m-1)p.pb(ed[s].fst),s=to[s];
	for(auto i:p)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}

