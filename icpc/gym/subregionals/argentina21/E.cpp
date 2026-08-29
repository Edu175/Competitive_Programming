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
	ll n; cin>>n;
	vv a(n),d(n);
	fore(i,0,n)cin>>a[i]>>d[i];
	ll t=0,w=0;
	vv bag;
	ll i=0;
	while(i<n||SZ(bag)){
		if(i<n&&t>a[i]){
			if(w==d[i])t=a[i]+10;
			else bag.pb(i);
			i++;
		}
		else {
			if(SZ(bag))t+=10,w^=1,bag.clear();
			else t=a[i]+10,w=d[i];
		}
	}
	cout<<t<<"\n";
	return 0;
}
