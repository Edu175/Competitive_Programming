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
		ll n,k; cin>>n>>k;
		vv a(n+1);
		fore(i,1,n+1)cin>>a[i];
		ll res=-k*10*n;
		for(ll i=n;i;i--){
			fore(j,max(res/i,1ll),n+1)if(i!=j){
				// cout<<i<<" "<<j<<": "<<i*j-k*(a[i]|a[j])<<"\n";
				res=max(res,i*j-k*(a[i]|a[j]));
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
