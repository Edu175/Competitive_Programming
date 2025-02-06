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
// const ll C=105;
// largest gap 1442

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r,g; cin>>l>>r>>g;
		l=(l+g-1)/g;
		r=r/g;
		ll a=-1,b=-2;
		auto proba=[&](ll i, ll j){
			ll cop=gcd(i,j)==1;
			if(cop&&j-i>b-a){
				a=i,b=j;
			}
			return cop;
		};
		fore(i,l,r+1){
			if(r-i<=b-a)break;
			for(ll j=r;j>=i;j--)if(proba(i,j))break;
		}
		if(a!=-1)a*=g,b*=g;
		else b++;
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}
