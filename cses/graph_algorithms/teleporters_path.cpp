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
	vector<ll>to(m,-1),ord;
	fore(i,0,m)ord.pb(i);
	fore(x,0,n){
		vector<ii>ca,cb;
		for(auto a:in[x])ca.pb({uf_find(a),a});
		for(auto b:out[x])cb.pb({uf_find(b),b});
		for(auto [a,i]:ca)if(SZ(cb)){
			if(SZ(cb)==1)to[i]=cb.back().snd;
			else {
				auto [b1,j1]=cb.back(); cb.pop_back();
				auto [b2,j2]=cb.back(); cb.pop_back();
				if(a!=b1)to[a]=j1,uf_join(a,b1),cb.pb({b2,j2});
				else to[a]=j2,uf_join(a,b2),cb.pb({b1,j1});
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

