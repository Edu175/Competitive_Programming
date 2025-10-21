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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS= 1e-10;

int main(){FIN;
	ll x,y; cin>>x>>y;
	ll sw=x*y<0;
	ld d=sqrtl(x*x+y*y);
	ll p=floor(d);
	ll t=ceil(d);
	ll res=0; // 0 white
	if(abs(d-p)<EPS||abs(d-t)<EPS)res=1;
	else {
		res=p%2==0;
		res^=sw;
	}
	if(res)cout<<"black\n";
	else cout<<"white\n";
	return 0;
}
