#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

struct UF{
	int uf[MAXN];
	UF(){}
	void init(){mset(uf,-1);}
	int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		if(uf[x]>uf[y])swap(x,y); // y -> x
		uf[x]+=uf[y];uf[y]=x;
		return true;
	}
	bool same(ll x, ll y){
		return find(x)==find(y);
	}
};

UF g[12];
ll res=0;
void add(ll x, ll y, ll w){
	if(!g[w].same(x,y)){
		res+=w;
		fore(j,w+1,11)if(g[j].same(x,y)){
			res-=j;
			break;
		}
	}
	fore(j,w,11)g[j].join(x,y);
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,1,11)g[i].init();
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		add(u,v,w);
	}
	while(q--){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		add(u,v,w);
		cout<<res<<"\n";
	}
	return 0;
}
