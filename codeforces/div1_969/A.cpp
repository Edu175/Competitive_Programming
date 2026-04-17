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
		ll n; cin>>n;
		vv deg(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			deg[u]++;
			deg[v]++;
		}
		string s; cin>>s;
		vv c(2);
		ll rest=0,skip=0;
		fore(i,1,n){
			if(deg[i]==1){
				if(s[i]=='?')rest++;
				else c[(s[i]-'0')^1]++;
			}
			else skip+=s[i]=='?';
		}
		ll res=0;
		if(s[0]=='?'){
			res=max(c[0],c[1])+rest/2;
		}
		else {
			res=c[s[0]-'0']+(rest+1)/2;
		}
		if(skip%2&&c[0]==c[1]&&rest%2&&s[0]=='?')res++;
		cout<<res<<"\n";
	}
	return 0;
}
