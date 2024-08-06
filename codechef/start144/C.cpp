#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,l,r; cin>>n>>l>>r; l--,r++;
		ll p=0,sum=0;
		for(ll i=n;i;i--){
			sum+=i;
			if(sum>=r-l){
				p=i-1;
				break;
			}
		}
		auto suma=[&](ll x, ll n){
			vector<ll>ret;
			for(ll i=n;i;i--)if(x>=i){
				ret.pb(i);
				x-=i;
			}
			return ret;
		};
		auto res=suma(l,p);
		vector<ll>vis(n+1);
		for(auto i:res)vis[i]=1;
		fore(i,p+1,n+1)res.pb(i),vis[i]=1;
		fore(i,1,n+1)if(!vis[i])res.pb(i);
		imp(res);
	}
	return 0;
}
