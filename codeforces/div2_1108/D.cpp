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
const ll B=20;
#define ppc __builtin_popcountll
ll cost(ll x){return __lg(x)+ppc(x);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll res=accumulate(ALL(a),0ll)+1000;
		for(ll pot=1,j=0;j<B;pot+=pot,j++){
			ll cur=j;
			fore(i,0,n){
				ll x=a[i];
				ll y=(x+pot-1)/pot*pot;
				cur+=y-x;
				y/=pot;
				ll best=cost(y);
				ll mv=0;
				while(mv<best){
					y++;
					mv+=pot;
					best=min(best,mv+cost(y));
				}
				cur+=best;
			}
			res=min(res,cur);
			// cerr<<j<<": "<<cur<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
