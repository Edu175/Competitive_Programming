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
		vv a(n),r(n);
		fore(i,0,n)cin>>a[i];
		vv ans(n);
		ll s=0;
		fore(i,0,n){
			s+=a[i];
			r[i]=s%10;
			s/=10;
		}
		ll d=0;
		for(ll i=n-1;i>=0;i--){
			s*=10; s+=r[i]; d*=10;
			
			ans[i]=s/m;
			ll am=s/m*m;
			s-=am;
			
			d+=am;
			ll u=min(a[i],d);
			a[i]-=u; d-=u;
			s-=a[i];
		}
		assert(!d);
		// imp(ans)
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
