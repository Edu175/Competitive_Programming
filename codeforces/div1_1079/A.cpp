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
		ll p,q; cin>>p>>q;
		ll a=p%2,b=q%3;
		ll n=-1;
		fore(i,0,6)if(n==-1&&i%2==a&&i%3==b)n=i;
		p-=n,q-=n;
		assert(p%2==0&&q%3==0);
		if(p<=0||q<=0){
			cout<<"Alice\n";
			continue;
		}
		if(p/2==q/3){
			cout<<"Bob\n";
			continue;
		}
		ll l=0,r=p;
		while(r-l>1){
			ll m=(l+r)/2;
			ll pi=p-6*m,qi=q-6*m;
			if(pi>0&&qi>0&&(pi/2>qi/3)==(p/2>q/3))l=m;
			else r=m;
		}
		ll bob=0;
		auto tr=[&](ll m){
			ll pi=p-6*m,qi=q-6*m;
			if(pi>0&&qi>0&&(pi/2==qi/3))bob=1;
		};
		tr(l),tr(r);
		if(bob)cout<<"Bob\n";
		else cout<<"Alice\n";
	}
	return 0;
}
