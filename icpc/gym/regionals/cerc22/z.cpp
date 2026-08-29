#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n) cin>>a[i];
	while(q--){
		ll x,d; cin>>x>>d;x--;
		ll ans = 1e17;
		ll acc  = 0;
		fore(i,0,d){
			acc += a[x+i];
			ans = min(ans,acc/(i+1));
		}
		if(ans < 0) cout<<"stay with parents\n";
		else cout<<ans<<"\n";
	}
	return 0;
}