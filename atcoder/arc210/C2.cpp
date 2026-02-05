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
		fore(i,0,n)cin>>a[i];
		vv ans(n);
		for(ll i=n-1;i>=0;i--){
			ll c=0;
			ll s=max(0ll,i-12);
			fore(j,s,i+1){
				c/=10;
				c+=a[j];
			}
			ans[i]=c/m;
			ll q=c/m*m;
			for(ll j=i;j>=s;j--){
				ll u=min(a[j],q);
				q-=u;
				a[j]-=u;
				q*=10;
			}
			assert(q==0);
		}
		imp(ans)
		// pasada a ans
		vv res;
		for(ll i=0,s=0;i<n||s>0;i++){
			if(i<n)s+=ans[i];
			ll r=s%10;
			res.pb(r);
			s/=10;
		}
		while(SZ(res)&&!res.back())res.pop_back();
		if(!SZ(res))res.pb(0);
		reverse(ALL(res));
		for(auto i:res)cout<<i;
		cout<<"\n";
	}
	return 0;
}
