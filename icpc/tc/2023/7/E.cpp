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
		ll n; cin>>n;
		vector<ll> a;
		fore(i,0,n){
			char c; cin>>c;
			if(c=='*')a.pb(i);
		}
		// if(!SZ(a))cout<<"0\n";
		n=SZ(a);
		ll fij=0,res=0;
		fore(i,0,n){
			fij-=abs(i-n/2);
			res+=abs(a[i]-a[n/2]);
		}
		res+=fij;
		cout<<res<<"\n";
	}
	return 0;
}
