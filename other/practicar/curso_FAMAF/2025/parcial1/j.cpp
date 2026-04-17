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
		string s; cin>>s;
		ll n=SZ(s);
		vector<vv> to(n+2,vv(10,n+1));
		for(ll i=n-1;i>=0;i--){
			to[i]=to[i+1];
			to[i][s[i]-'0']=i+1;
		}
		ll m; cin>>m;
		string l,r; cin>>l>>r;
		string ans;
		ll p=0;
		fore(i,0,m){
			ll mx=-1;
			fore(j,l[i]-'0',r[i]-'0'+1)mx=max(mx,to[p][j]);
			p=mx;
			// cout<<i<<" "<<p<<"\n";
		}
		if(p>=n+1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}