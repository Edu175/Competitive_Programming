#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdkfjg:v)cout<<sdkfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(2*n);
	fore(i,0,2*n)cin>>a[i];
	auto solve=[&](vector<ll>a){
		ll res=0;
		fore(i,0,n){
			res+=max(a[i]+a[i+n],-(a[i]+a[i+n]));
		}
		return res;
	};
	ll res=solve(a);
	fore(i,0,n)a[i]=-a[i];
	res=max(res,solve(a));
	cout<<res<<"\n";
	return 0;
}