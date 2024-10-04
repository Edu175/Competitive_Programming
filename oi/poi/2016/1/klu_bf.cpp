#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll B; cin>>B;
	ll n=1<<B;
	vector<ll>a(n);
	fore(i,0,n/2){
		ll u,v; cin>>u>>v;
		a[u]=v;
		a[v]=u;
	}
	vector<unordered_map<ll,bool>> dp(n);
	ll u=(1ll<<n)-1;
	auto f=[&](ll mk, ll x, auto &&f)->bool{
		if(dp[x].count(mk))return dp[x][mk];
		auto &res=dp[x][mk];
		if(mk==u)return res=__builtin_popcount(x)==1;
		fore(j,0,B){
			ll y=x^(1ll<<j);
			if(mk>>y&1)continue;
			if(f(mk|(1ll<<y)|(1ll<<a[y]),a[y],f))return res=1;
		}
		return res;
	};
	ll mk=1|(1ll<<a[0]),x=a[0];
	ll res=f(mk,x,f);
	if(!res)cout<<"NIE\n";
	else {
		vector<ll>res={0,a[0]};
		while(mk!=u){
			ll _y=-1;
			fore(j,0,B){
				ll y=x^(1ll<<j);
				if(mk>>y&1)continue;
				if(f(mk|(1ll<<y)|(1ll<<a[y]),a[y],f)){_y=y;break;}
			}
			res.pb(_y);
			res.pb(a[_y]);
			mk|=(1ll<<_y)|(1ll<<a[_y]);
			x=a[_y];
		}
		for(auto i:res)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
}