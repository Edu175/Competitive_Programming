#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v).sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){ET;
	string s; cin>>s;
	ll n=SZ(s);
	vv ds;
	fore(i,1,n+1)if(n%i==0)ds.pb(i);
	vv good(n+1);
	fore(i,0,SZ(ds)){
		ll d=ds[i];
		vv can(d,1);
		fore(i,0,n)can[i%d]&=s[i]=='R';
		ll flag=0;
		fore(i,0,d)flag|=can[i];
		good[d]=flag;
	}
	// for(auto i:good)cout<<i<<" ";;cout<<"\n";
	ll res=0;
	fore(k,1,n){
		if(good[gcd(n,k)]){
			// cout<<k<<" god\n";
			res++;
		}
	}
	cout<<res<<"\n";
}