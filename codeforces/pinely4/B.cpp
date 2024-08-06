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
		ll n; cin>>n;
		vector<ll>b(n-1),a(n);
		fore(i,0,n-1)cin>>b[i];
		// a[0]=b[0];
		fore(i,0,n-1){
			a[i]|=b[i];
			a[i+1]|=b[i];
		}
		vector<ll>c;
		fore(i,0,n-1)c.pb(a[i]&a[i+1]);
		// imp(a) imp(c)
		if(b==c){
			imp(a);
		}
		else cout<<"-1\n";
		// cout<<"\n";
	}
	return 0;
}
