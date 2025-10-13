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
const ll B=4e4+5,INF=1e18;
ll dt(ll a, ll b){return (a+b-1)/b;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,s; cin>>n>>m>>s;
		auto get=[&](ll v){
			ll r=dt(n,v);
			ll r2=s/r;
			if(!r2)return INF;
			ll h=dt(m,r2);
			return v+h-2;
		};
		ll res=n+m+5;
		fore(v,1,B){
			res=min(res,get(v));
			res=min(res,get(dt(n,v)));
		}
		cout<<res<<"\n";
	}
	return 0;
}
