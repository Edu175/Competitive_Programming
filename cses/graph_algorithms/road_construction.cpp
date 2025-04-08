#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
	if((x=uf_find(x))==(y=uf_find(y)))return 0;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return 1;
}

int main(){FIN;
	mset(uf,-1);
	ll n,m; cin>>n>>m;
	ll mx=1,cnt=n;
	while(m--){
		ll u,v; cin>>u>>v; u--,v--;
		cnt-=uf_join(u,v);
		mx=max(mx,-uf[uf_find(u)]);
		cout<<cnt<<" "<<mx<<"\n";
	}
	return 0;
}
