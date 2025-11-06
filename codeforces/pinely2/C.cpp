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
		ll n,k; cin>>n>>k;
		vv a(n);
		set<ll> st;
		fore(i,0,n+1)st.insert(i);
		fore(i,0,n)cin>>a[i],st.erase(a[i]);
		ll am=k*n;
		a.pb(*st.begin());
		ll p=(n+am)%(n+1);
		ll x=a[p];
		ll r=k;
		// cout<<r<<" r\n";
		r=(n+1-r%(n+1))%(n+1);
		rotate(a.begin(),a.begin()+r,a.end());
		a.erase(find(ALL(a),x));
		imp(a)
	}
	return 0;
}
