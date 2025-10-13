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
const ll INF=1e18;
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<vv> a(m);
	fore(i,0,n){
		ll u,c; cin>>u>>c; u--;
		a[u].pb(c);
	}
	fore(i,0,m)sort(ALL(a[i]));
	auto f=[&](ll k){
		ll q=SZ(a[0]);
		vv cand;
		ll res=0;
		fore(i,1,m){
			ll sz=SZ(a[i]);
			ll cant=max(sz-k,0ll);
			fore(j,0,sz){
				if(j<cant)res+=a[i][j],q++;
				else cand.pb(a[i][j]);
			}
		}
		sort(ALL(cand));
		fore(i,0,k+1-q){
			if(i>=SZ(cand))return INF;
			res+=cand[i];
		}
		return res;
	};
	ll res=INF;
	fore(i,0,n+1)res=min(res,f(i));
	cout<<res<<"\n";
	return 0;
}
