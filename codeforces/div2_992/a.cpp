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
		vv pos[k];
		fore(i,0,n){
			ll x; cin>>x;
			pos[x%k].pb(i);
		}
		ll res=-1;
		fore(i,0,k)if(SZ(pos[i])==1)res=pos[i][0];
		if(res==-1)cout<<"NO\n";
		else {
			cout<<"YES\n"<<res+1<<"\n";
		}
	}
	return 0;
}
