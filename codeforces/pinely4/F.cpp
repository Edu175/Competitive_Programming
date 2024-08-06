#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

ll hay(vector<ll>a){
	ll n=SZ(a);
	// cout<<"hay "; imp(a);
	
	fore(i,0,n-2){
		if(a[i]+a[i+1]>a[i+2])return 1;
	}
	// cout<<"no\n";
	return 0;
}

ll solve(vector<ll>&a){
	sort(ALL(a));
	// cout<<"solve "; imp(a);
	ll n=SZ(a);
	fore(i,2,n){
		ll p=upper_bound(ALL(a),a[i]-a[i-1])-a.begin();
		// cout<<i<<": "<<p<<"\n";
		if(p>i-2)continue;
		vector<ll>b;
		fore(j,0,n)if(j!=i&&j!=i-1&&j!=p)b.pb(a[j]);
		if(hay(b))return 1;
	}
	// cout<<"no\n";
	return 0;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	while(q--){
		ll l,r; cin>>l>>r; l--;
		r=min(r,l+50);
		vector<ll>b;
		fore(i,l,r)b.pb(a[i]);
		if(solve(b))cout<<"YES\n";
		else cout<<"NO\n";
	}
		
	
	return 0;
}
