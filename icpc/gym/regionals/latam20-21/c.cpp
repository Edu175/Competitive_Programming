#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ET
	ll n; cin>>n;
	vv a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	fore(i,0,n)a[i]=a[i]-sum/n;
	auto solve=[&](vv a){
		ll res=0,v=0;
		fore(i,0,n*4){
			ll p=i%n;
			if(a[p]<0){
				ll c=min(v,-a[p]);
				a[p]+=c;
				v-=c;
			}
			else v+=a[p],a[p]=0;
			res+=v;
		}
		return res;
	};
	ll res=solve(a);
	reverse(ALL(a));
	res=min(res,solve(a));
	cout<<res<<"\n";
}