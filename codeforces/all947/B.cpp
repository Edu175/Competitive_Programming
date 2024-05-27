#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
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
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		vector<ll>b;
		fore(i,0,n)if(a[i]%a[0])b.pb(a[i]);
		a=b;
		b.clear();
		sort(ALL(a));
		fore(i,0,SZ(a))if(a[i]%a[0])b.pb(a[i]);
		if(SZ(b))cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
