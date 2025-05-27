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
		ll n,m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]++;
		vv ids;
		fore(i,0,n)ids.pb(i);
		for(ll i=n-2;i>=0;i--)ids.pb(i);
		vv res(m);
		vv t(n);
		fore(r,0,m)for(auto i:ids){
			if(t[i]<=0)res[r]++,t[i]=a[i],cout<<r<<": "<<i<<"\n";
			fore(j,0,n)t[j]--;
		}
		imp(res)
	}
	return 0;
}
