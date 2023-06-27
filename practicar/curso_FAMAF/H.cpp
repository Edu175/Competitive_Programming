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

ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return (uf[x]<0?x:uf[x]=uf_find(uf[x]));}
ll uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return 0;
	if(-uf[x]>-uf[y])swap(x,y);
	uf[y]+=uf[x];
	uf[x]=y;
	return 1;
}
vector<pair<ll,ii>>ed;

ll kruskal(){
	sort(ALL(ed));
	ll res=0;
	for(auto i:ed)res+=uf_join(i.snd.fst,i.snd.snd)*i.fst;
	return res;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n],mn=0;
	fore(i,0,n){
		cin>>a[i];
		if(a[i]<a[mn])mn=i;
	}
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({w,{u,v}});
	}
	fore(i,0,n)ed.pb({a[i]+a[mn],{i,mn}});
	uf_init();
	cout<<kruskal()<<"\n";
	return 0;
}
