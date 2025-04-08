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

ll solve(vv a){
	ll res=a[0];
	ll mx=0;
	fore(i,1,SZ(a))mx=max(mx,a[i]);
	return res+mx;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		if(k>=2){
			sort(ALL(a));
			reverse(ALL(a));
			ll res=0;
			fore(i,0,k+1)res+=a[i];
			cout<<res<<"\n";
		}
		else {
			ll res=solve(a);
			reverse(ALL(a));
			res=max(res,solve(a));
			cout<<res<<"\n";
		}
	}
	return 0;
}
