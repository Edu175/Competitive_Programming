#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcon=b;i<mxcon;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);;cout.tie(0);
#define imp(v) {for(auto kjdfhg:v)cout<<kjdfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y],uf[y]=x;
}
bool same(ll x, ll y){return uf_find(x)==uf_find(y);}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	ll q; cin>>q;
	vector<ll>xs(q),ys(q),zs(q),ls(q),rs(q);
	vector<ll> qs[m];
	fore(i,0,q){
		auto &l=ls[i],&r=rs[i],&x=xs[i],&y=ys[i],&z=zs[i];
		cin>>x>>y>>z; x--,y--;
		l=0,r=m-1;
		ll mid=(l+r)/2;
		qs[mid].pb(i);
	}
	while(1){
		ll hay=0;
		uf_init();
		fore(t,0,m){
			uf_join(ed[t].fst,ed[t].snd);
			for(auto i:qs[t]){
				hay=1;
				auto &l=ls[i],&r=rs[i],&x=xs[i],&y=ys[i],&z=zs[i];
				ll k=-uf[uf_find(x)]-(!same(x,y))*uf[uf_find(y)];
				if(k>=z)r=t-1;
				else l=t+1;
			}
			qs[t].clear();
		}
		fore(i,0,q){
			auto &l=ls[i],&r=rs[i];
			if(l<=r){
				ll mid=(l+r)/2;
				qs[mid].pb(i);
			}
		}
		if(!hay)break;
	}
	fore(i,0,q){
		cout<<ls[i]+1<<"\n";
	}
	
	return 0;
}