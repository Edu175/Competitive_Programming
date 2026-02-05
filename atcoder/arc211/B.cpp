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
	ll x,y,z; cin>>x>>y>>z;
	vv a=vv(y),b=vv(x),c=vv(y);
	ll q=z-x;
	ll ty=x!=y;
	fore(i,0,q)b.pb(ty),c.pb(ty);
	cout<<SZ(a)<<" ";for(auto i:a)cout<<i<<" ";;cout<<"\n";
	cout<<SZ(b)<<" ";for(auto i:b)cout<<i<<" ";;cout<<"\n";
	cout<<SZ(c)<<" ";for(auto i:c)cout<<i<<" ";;cout<<"\n";
	return 0;
}
