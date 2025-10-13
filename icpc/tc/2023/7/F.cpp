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

ll k;
ii greedy(ll u, ll a, ll b){ // termine con u del tipo a (0 sino)
	ll sw=0;
	if(a>=b){
		a-=(k-u);
		b--;
		swap(a,b); sw=1;
	}
	// hay mas de b
	b-=k*a;
	if(b<=0)return {0,0};
	return {b,1^sw};
}

int main(){FIN;
	ll n; cin>>n>>k;
	vv as(n),bs(n);
	fore(i,0,n)cin>>as[i];
	fore(i,0,n)cin>>bs[i];
	ll u=0,ty=0;
	fore(i,0,n){
		ll a=as[i],b=bs[i];
		if(ty)swap(a,b);
		auto [up,tp]=greedy(u,a,b);
		if(up>k){
			cout<<"NO\n";
			exit(0);
		}
		if(ty)tp^=1;
		u=up; ty=tp;
	}
	cout<<"YES\n";
	return 0;
}
