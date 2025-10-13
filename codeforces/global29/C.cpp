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
		string s; cin>>s;
		ll q=0;
		vv pos;
		vv is(n);
		fore(i,0,n){
			q++;
			if(i==n-1||s[i]!=s[i+1]){
				if(s[i]=='0'&&q==1){
					pos.pb(i);
					is[i]=1;
				}
				q=0;
				// cout<<"bad "<<i<<"\n";
			}
		}
		vv vis(n);
		ll fg=1;
		for(auto i:pos)if(!vis[i]){
			ll good=i==0||i==n-1;
			if(i>=2)good|=s[i-2]=='0'&&!is[i-2];
			if(i+2<n)good|=s[i+2]=='0'&&!is[i+2];
			// cout<<i<<": "<<good<<"\n";
			if(good){
				is[i]=0;
				continue;
			}
			if(i+2<n&&s[i+2]=='0'){
				vis[i+2]=1;
			}
			else fg=0;
		}
		if(fg)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
