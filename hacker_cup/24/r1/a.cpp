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
typedef long double ld;
const ld EPS=1e-7;

int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		ll n; cin>>n;
		ld s=-1,e=-1;
		fore(i,1,n+1){
			ll l,r; cin>>l>>r;
			// cout<<i<<": "<<l<<","<<r<<": ";
			ld a=ld(l)/i,b=ld(r)/i;
			// cout<<a<<","<<b<<"\n";
			
			if(s==-1)s=a,e=b;
			s=max(s,a);
			e=min(e,b);
			// cout<<i<<": "<<l<<","<<r<<": "<<a<<","<<b<<"\n";
		}
		// cout<<s<<","<<e<<" = ";
		if(!(s<=e+EPS))cout<<"-1\n";
		else cout<<fixed<<setprecision(15)<<1.0/e<<"\n";
		// cout<<"\n\n";
	}
	return 0;
}
