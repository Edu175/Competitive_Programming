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
		ll n; cin>>n;
		vv a(n);
		ll z=0,gaps=0;
		fore(i,0,n){
			cin>>a[i],z+=a[i]==0;
		}
		fore(i,0,n){
			if(a[i]){
				if(i==n-1||!a[i+1])gaps++;
			}
		}
		// cout<<gaps<<" g\n";
		ll res=0;
		if(z==n)res=0;
		else if(gaps==1)res=1;
		else res=2;
		cout<<res<<"\n";
	}
	return 0;
}
