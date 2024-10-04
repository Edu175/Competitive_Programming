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
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<vector<ll>>sp(3,vector<ll>(n+1));
		fore(h,0,3)fore(i,1,n+1){
			sp[h][i]=sp[h][i-1]+(a[i-1]==h);
		}
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll mx=0;
			fore(h,0,3)mx=max(mx,sp[h][r]-sp[h][l]);
			ll sz=r-l;
			// cout<<l<<","<<r<<": "<<sz<<" "<<mx<<"\n";
			if(sz&1||mx!=sz/2)cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}
