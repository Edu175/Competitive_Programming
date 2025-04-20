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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		map<ll,ll>xs,ys;
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			y+=x;
			xs[x]^=1;
			ys[y]^=1;
		}
		ll x=-1,y=-1;
		for(auto i:xs)if(i.snd)x=i.fst;
		for(auto i:ys)if(i.snd)y=i.fst;
		y-=x;
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
