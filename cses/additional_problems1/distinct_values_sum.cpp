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

ll num(ll n){return n*(n+1)/2;}

int main(){FIN;
	ll n; cin>>n;
	map<ll,vv> pos;
	fore(i,0,n){
		ll x; cin>>x;
		pos[x].pb(i);
	}
	ll res=0;
	for(auto [asd,v]:pos){
		ll u=-1;
		v.pb(n);
		ll cur=num(n);
		for(auto i:v)cur-=num(i-u-1),u=i;
		res+=cur;
	}
	cout<<res<<"\n";
	return 0;
}