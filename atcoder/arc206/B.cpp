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

ll lis(vv a){
	vv v;
	for(auto i:a){
		auto p=lower_bound(ALL(v),i)-v.begin();
		if(p==SZ(v))v.pb(i);
		else v[p]=i;
	}
	return SZ(v);
}

int main(){FIN;
	ll n; cin>>n;
	vv z(n),c(n);
	fore(i,0,n)cin>>z[i];
	vector<vv> h(n);
	fore(i,0,n){
		cin>>c[i];
		c[i]--;
		h[c[i]].pb(z[i]);
	}
	ll res=0;
	fore(i,0,n){
		auto a=h[i];
		res+=(SZ(a)-lis(a))*(i+1);
		// cout<<i<<": "; imp(a)
		// cout<<SZ(a)<<" "<<lis(a)<<"\n";
		
		// cout<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
