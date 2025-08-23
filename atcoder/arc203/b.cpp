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

ll ty(vv a){
	if(count(ALL(a),1)>1)return -1;
	ll fg0=!a[0];
	ll fg1=!a.back();
	return fg0+2*fg1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		if(count(ALL(a),1)!=count(ALL(b),1)){
			cout<<"No\n";
			continue;
		}
		ll ta=ty(a);
		ll tb=ty(b);
		if(ta==tb)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
