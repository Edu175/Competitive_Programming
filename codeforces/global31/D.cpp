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
const ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll l=0,r=INF,res=0;
		fore(i,1,n){
			ll d=a[i]-a[i-1];
			ll cap=d;
			if(i+1<n)cap=min(cap,a[i+1]-a[i]);
			ll lp=d-r;
			ll rp=d-l;
			lp=max(lp,0ll);
			rp=min(rp,cap);
			// cout<<l<<","<<r<<" "<<lp<<","<<rp<<"\n";
			if(!(lp==0&&rp==0)&&lp<=rp)res++,l=lp,r=rp;
			else {
				l=0,r=cap;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
