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
		ll n,k,x; cin>>n>>k>>x;
		vv a(n);
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		ll res=0,acum=0,did=0;
		fore(i,0,k){
			acum+=sum;
			if(acum>=x){acum-=sum;did=1;break;}
			res+=n;
		}
		if(did){
			for(ll i=n-1;i>=0;i--){
				acum+=a[i];
				res+=acum<x;
			}
		}
		// cerr<<did<<" ";
		res=n*k-res;
		cout<<res<<"\n";
	}
	return 0;
}
