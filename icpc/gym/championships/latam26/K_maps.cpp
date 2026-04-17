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
const ll MAXN=4005;

ii a[MAXN];

set<ii> vis;
unordered_map<ll,ll> xs,ys;

set<ii> ms;
bool good;
ll len;
ii rt;
void doit(ii x, ll w){
	while(1){
		ll k=w?x.snd:x.fst;
		auto &mp=w?ys:xs;
		if(!mp.count(k)){good=0;return;}
		if(vis.count(x)){
			good&=w&&rt==x;
			return;
		}
		vis.insert(x);
		
		ii m={k,mp[k]}; if(w)swap(m.fst,m.snd);
		if(ms.count(m))good=0;
		ms.insert(m);
		// cerr<<"dfs "<<x.fst<<","<<x.snd<<": "<<m.fst<<","<<m.snd<<": ";
		ll dx=m.fst-x.fst;
		ll dy=m.snd-x.snd;
		x.fst+=2*dx;
		x.snd+=2*dy;
		ll dif=abs(2*dx)+abs(2*dy);
		len+=dif;
		// if(!dif){good=0;return;}
		assert(dif);
		// cerr<<x.fst<<","<<x.snd<<"\n";
		w^=1;
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd;
		xs[a[i].fst]=a[i].snd;
		ys[a[i].snd]=a[i].fst;
	}
	ll res=0;
	fore(i,0,n)fore(j,0,n)if(i!=j){
		ii cur={a[i].fst,a[j].snd};
		// cerr<<"new cycle\n";
		good=1,len=0; ms.clear(); rt=cur;
		doit(cur,1);
		// cerr<<good<<" "<<len<<"\n\n";
		if(good)res=max(res,len);
	}
	cout<<res<<"\n";
	return 0;
}