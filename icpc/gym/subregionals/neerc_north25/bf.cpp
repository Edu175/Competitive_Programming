#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;
ll lis(vv a){
	vv v;
	for(auto i:a){
		ll p=lower_bound(ALL(v),i)-v.begin();
		if(p>=SZ(v))v.pb(i);
		else v[p]=i;
	}
	return SZ(v);
}

int main(){
	FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		while(q--){
			ll l,r; cin>>l>>r; l--;
			vv b;
			fore(i,l,r)b.pb(a[i]);
			cout<<lis(b)<<"\n";
		}
	}
	return 0;
}