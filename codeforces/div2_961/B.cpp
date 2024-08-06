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
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll p=0,sum=0,res=0;
		fore(i,0,n){
			while(p<n&&a[p]-a[i]<=1&&sum+a[p]<=k)sum+=a[p++];
			// cout<<i<<" "<<p<<": "<<sum<<"\n";
			res=max(res,sum);
			sum-=a[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}
