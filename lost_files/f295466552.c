#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>vis(n+1);
		vector<ll>res;
		fore(i,1,n+1){
			if(vis[i])continue;
			ll x=i;
			while(x<=n){
				if(vis[x])continue;
				res.pb(x);
				vis[x]=1;
				x*=2;
			}
		}
		imp(res);
	}
	return 0;
}
