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

struct pt{ll x,y;};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; pt a,b; cin>>n>>a.x>>a.y>>b.x>>b.y;
		ll res=0;
		if(a.x<b.x)res=max(res,b.x);
		if(a.y<b.y)res=max(res,b.y);
		if(a.x>b.x)res=max(res,n-b.x);
		if(a.y>b.y)res=max(res,n-b.y);
		cout<<res<<"\n";
	}
	return 0;
}
