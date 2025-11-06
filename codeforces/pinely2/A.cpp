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
		ll n,a,q; cin>>n>>a>>q;
		string s; cin>>s;
		ll c=count(ALL(s),'+');
		if(c+a<n)cout<<"NO\n";
		else {
			ll fg=a==n;
			for(auto i:s){
				a+=i=='+'?1:-1;
				fg|=a==n;
			}
			if(fg)cout<<"YES\n";
			else cout<<"MAYBE\n";
		}
	}
	return 0;
}
