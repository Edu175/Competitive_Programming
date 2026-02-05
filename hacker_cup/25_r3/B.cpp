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
const ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		ll n; cin>>n;
		vv c(n),a(n);
		fore(i,0,n)cin>>c[i];
		fore(i,0,n)cin>>a[i];
		vv sp(n+1);
		fore(i,1,n+1)sp[i]=a[i-1]+sp[i-1];
		vv is(n);
		ll mx=0;
		fore(i,0,n)if(a[i]>mx)mx=a[i],is[i]=1;
		if(mx==0){
			cout<<"0\n";
			continue;
		}
		vv dp(n);
		ll ans=0;
		// cout<<"\n";
		fore(i,0,n)if(is[i]){
			ll k=a[i];
			vv ev(n+1,-1);
			fore(j,0,i)if(is[j]){
				ll pos=j-a[j]+2;
				ev[pos]=max(ev[pos],j);
			}
			ll p=-1,sum=0;
			fore(i,0,k)sum+=c[i];
			auto &res=dp[i];
			res=INF;
			// cout<<"dp "<<i<<"\n";
			fore(t,0,i-k+2){
				p=max(p,ev[t]);
				ll cur=sum+(p==-1?0ll:dp[p]);
				res=min(res,cur);
				if(t+k<n)sum+=-c[t]+c[t+k];
				// cout<<"tried "<<t<<": "<<p<<": "<<cur<<"\n";
			}
			ans=res;
			// cout<<"= "<<res<<"\n\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
