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
	fore(caso,0,t){
		cout<<"Case #"<<caso+1<<": ";
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll s=a[0];
		s+=max(0ll,n-2)*a[0]*2;
		cout<<(s<=k?"YES\n":"NO\n");
	}
	return 0;
}
