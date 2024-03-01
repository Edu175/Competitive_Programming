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
const ll B=61;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>res={n};
		ll flag=0;
		ll msb=63-__builtin_clzll(n);
		if((m>>msb)||(n^(1ll<<msb))>=m){
			res.pb(m|(1ll<<msb));
			res.pb(m);
		}
		else {
			ll c[4]={};
			for(ll i=msb-1;i>=0;i--){
				c[((n>>i)&1)*2+((m>>i)&1)]++;
				if(c[3]&&!c[1])flag=1;
			}
			if(flag)res.pb(m);
		}
		vector<ll>ans;
		for(auto i:res)if(!SZ(ans)||ans.back()!=i)ans.pb(i);
		res=ans;
		if(SZ(res)==1)cout<<"-1\n";
		else {
			cout<<SZ(res)-1<<"\n";
			imp(res);
		}
	}
	return 0;
}
