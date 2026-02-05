#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005,LG=12;

struct UF{
	vector<int> uf;
	UF(int n):uf(n,-1){}
	UF(){}
	int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		if(uf[x]>uf[y])swap(x,y); // y -> x
		uf[x]+=uf[y];uf[y]=x;
		return true;
	}
	bool same(int x, int y){return find(x)==find(y);}
};

vector<UF> uf(1ll<<LG);

void conn(ll x, ll y, ll w){
	if(uf[w].same(x,y))return;
	uf[w].join(x,y);
	fore(j,0,LG)if(w>>j&1)conn(x,y,w^(1ll<<j));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,1ll<<LG)uf[i]=UF(n);
		ll ans=0;
		while(q--){
			char ty; cin>>ty;
			ll u,v; cin>>u>>v; u--,v--;
			if(ty=='+'){
				ll w; cin>>w;
				conn(u,v,w);
			}
			else {
				if(!uf[0].same(u,v)){
					// cout<<"-1\n";
					ans--;
					continue;
				}
				ll res=0;
				for(ll j=LG-1;j>=0;j--){
					ll cand=res|(1ll<<j);
					if(uf[cand].same(u,v))res=cand;
				}
				// cout<<res<<"\n";
				ans+=res;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
