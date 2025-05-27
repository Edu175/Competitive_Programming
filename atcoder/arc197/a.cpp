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
		ll n,m; cin>>n>>m;
		string s; cin>>s;
		auto getp=[&](char obj, char no){
			string p;
			vv c(26);
			c['R'-'A']=m-1;
			c['D'-'A']=n-1;
			for(auto i:s)if(i!='?')c[i-'A']--;
			// imp(c)
			fore(i,0,SZ(s)){
				char to=s[i];
				if(s[i]=='?'){
					// imp(c)
					if(c[obj-'A'])to=obj;
					else to=no;
					c[to-'A']--;
				}
				p.pb(to);
			}
			return p;
		};
		auto p0=getp('R','D');
		auto p1=getp('D','R');
		// cout<<p0<<" "<<p1<<"\n";
		ll z=1;
		ll res=z;
		fore(i,0,SZ(s)){
			if(p0[i]!=p1[i])z+=p0[i]=='D'?-1:1;
			res+=z;
		}
		cout<<res<<"\n";
	}
	return 0;
}
