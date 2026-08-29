#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

map<pair<ll,vv>,ll> dp;
vv cost;
ll n,m,k;

ll f(vv a, ll c){ // is winning for p
	sort(ALL(a));
	pair<ll,vv> key={c,a};
	if(dp.count(key))return dp[key];
	auto &res=dp[key];
	res=a[SZ(a)/2];
	// cerr<<a<<" "<<c<<"\n";
	fore(i,0,SZ(a))if(!i||a[i]!=a[i-1]){
		fore(v,1,m+1)if(c+cost[v]<=k){
			auto b=a;
			b[i]=(b[i])/v;
			res=min(res,f(b,c+cost[v]));
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		vv a(n);
		cost=vv(m+1);
		fore(i,0,n)cin>>a[i];
		fore(i,1,m+1)cin>>cost[i];
		sort(ALL(a));
		dp.clear();
		cout<<f(a,0)<<"\n";
	}
	return 0;
}
