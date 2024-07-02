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
		ll x,y,k; cin>>x>>y>>k;
		while(k&&x>1){
			// cout<<x<<" "<<y<<" "<<k<<endl;
			ll s=y-(x%y);
			s=min(s,k);
			x+=s;
			k-=s;
			while(x%y==0)x/=y;
		}
		// cout<<x<<" "<<y<<" "<<k<<endl;
		if(k){
			x=(x-1+k)%(y-1)+1;
			// if(!x)x=y;
		}
		cout<<x<<"\n";
	}
	return 0;
}
