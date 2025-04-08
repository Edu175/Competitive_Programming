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

ll get(vv a){
	vv c(2);
	ll l=0,n=SZ(a);
	if(a==vv(n))return 0;
	fore(i,0,n)if(a[i])c[i&1]++;
	// fore(i,0,n){
	// 	if(!a[i])l=i+1;
	// 	else if(i==n-1||!a[i+1]){
	// 		// cout<<l<<" "<<i<<"\n";
	// 		if((l+i)%2==0)c[l&1]++;
	// 	}
	// }
	ll res=max(1ll,abs(c[0]-c[1]));
	// cout<<"get "; for(auto i:a)cout<<i<<" ";
	// cout<<"= "<<res<<"\n";
	return res;
}
ll val(vv a){
	// cout<<"val "; for(auto i:a)cout<<i<<" ";;cout<<":\n";
	ll n=SZ(a),res=0;
	while(a!=vv(n)){
		res+=get(a);
		for(auto &i:a)if(i)i--;
	}
	// cout<<"= "<<res<<"\n";
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		cout<<val(a)<<"\n";
		// return 0;
		// ll res=0;
		// fore(l,0,n)fore(r,l+1,n+1){
		// 	vv b; fore(i,l,r)b.pb(a[i]);
		// 	res+=val(b);
		// }
		// cout<<res<<"\n";
	}
	return 0;
}
