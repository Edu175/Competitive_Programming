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
		ll n,x,y; cin>>x>>y>>n;
		vv a(n);
		a[0]=y,a.back()=x;
		fore(i,1,n-1){
			a[i]=a[i-1]-i;
		}
		if(a[n-2]-a[n-1]<n-1){
			cout<<"-1\n";
			continue;
		}
		reverse(ALL(a));
		imp(a);
	}
	return 0;
}
