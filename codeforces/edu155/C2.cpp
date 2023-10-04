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
const ll MOD=998244353;


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		vector<ll>p; ll q=1;
		fore(i,1,n){
			if(s[i]==s[i-1])q++;
			else p.pb(q),q=1;
		}
		p.pb(q);
		vector<ll>f(n+5,1);
		fore(i,1,n+5)f[i]=(f[i-1]*i)%MOD;
		ll op=0,wa=1;
		fore(i,0,SZ(p)){
			op=(op+p[i]-1)%MOD;
			wa=wa*p[i]%MOD;
		}
		wa=wa*f[op]%MOD;
		cout<<op<<" "<<wa<<"\n";
	}
	return 0;
}
