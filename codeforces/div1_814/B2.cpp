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
	vv fib={1,1};
	while(fib.back()<1e10)fib.pb(fib.end()[-2]+fib.end()[-1]);
	ll M=SZ(fib);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		ll tot=0;
		fore(i,0,n)cin>>a[i],tot+=a[i];
		ll m=0,sum=0;
		while(m<M&&sum<tot)sum+=fib[m++];
		if(m>=M||sum>tot){
			cout<<"NO\n";
			continue;
		}
		ll ant=-1;
		ll fg=1;
		for(ll i=m-1;i>=0;i--){
			ll mx=-1;
			fore(j,0,n)if(j!=ant){
				if(mx==-1||a[j]>a[mx])mx=j;
			}
			if(mx==-1){fg=0;break;}
			a[mx]-=fib[i];
			fg&=a[mx]>=0;
			ant=mx;
		}
		if(fg)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
