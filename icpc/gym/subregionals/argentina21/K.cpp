#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll k,T,n; cin>>k>>T>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];;
	a.pb(0);
	a.pb(T);
	sort(ALL(a));
	ll res=0;
	fore(i,0,SZ(a)-1){
		ll d=a[i+1]-a[i];
		res|=d>=k;
		// cerr<<i<<": "<<d<<"\n";
	}
	if(res)cout<<"Y\n";
	else cout<<"N\n";
	return 0;
}
