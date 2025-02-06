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
		ll n,k,l; cin>>n>>k>>l; k*=2; l*=2;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]*=2;
		ll s=a[0],t=k;
		fore(i,1,n)if(t<l){
			ll p=a[i];
			// cout<<t<<" "<<s<<" "<<p<<endl;
			if(abs(t-p)<=s)t+=k;
			else if(p<t)t=p+s+k;
			else {
				ll m=(t+p-s)/2;
				// cout<<"caso "<<m<<"\n";
				assert((t+p-s)%2==0);
				s+=m-t; t=m+k;
			}
		}
			// cout<<t<<" "<<s<<endl;
		if(t<l)s+=l-t;
		cout<<s<<"\n";
		// cout<<endl;
	}
	return 0;
}
