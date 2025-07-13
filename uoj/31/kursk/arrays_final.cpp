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
#pragma GCC optimize("Ofast") // may lead to precision errors
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnts,popcnt")
const ll MAXN=5e5+5;

ll a[MAXN];
ll v,res;
array<ll,4> bag[2][MAXN];
// array<ll,4> bag[MAXN],nxt[MAXN];

void iterative(ll s, ll e, ll l, ll r){
	ll po[2];
	po[0]=po[1]=0;
	bool w=0;
	#define put_back(bo) bag[w^bo][po[bo^w]++]
	
	put_back(0)={s,e,l,r};
	while(po[w]){
		ll sz=po[w]; po[w]=0;
		while(po[w]<sz){
			auto& [s,e,l,r]=put_back(0);
			ll m=(s+e)/2,val=v*m;
			ll p=lower_bound(a+l,a+r,val)-a;
			if(e-s==1){
				ll resi=a[p-1]-(val-v);
				if(resi>=v)resi%=v;
				res=max(res,resi);
				continue;
			}
			put_back(1)={s,m,l,p};
			put_back(1)={m,e,p,r};
		}
		w^=1;
		po[w^1]=0;
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		n=(unique(a,a+n))-a;
		res=0;
		if(n<=5005){
			fore(i,0,n)fore(j,i+1,n){
				res=max(res,a[j]%a[i]);
			}
			cout<<res<<"\n";
			continue;
		}
		for(ll i=n-1;i>=0;i--){
			if(res>=a[i]-1)break;
			ll mx=a[n-1]/a[i]+1;
			v=a[i];
			iterative(2,mx+1,i+1,n);
		}
		cout<<res<<"\n";
	}
	return 0;
}
