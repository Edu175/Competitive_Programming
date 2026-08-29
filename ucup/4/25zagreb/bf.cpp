#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		while(q--){
			ll x; cin>>x;
			vv b(n); fore(i,0,n)b[i]=a[i]+x;
			ll res=b[0];
			fore(l,0,n){
				ll sum=0;
				fore(r,l,n)sum+=b[r],res=max(res,sum);
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}