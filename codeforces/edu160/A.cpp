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
		string s; cin>>s;
		string a,b;
		a.pb(s[0]);
		ll e=SZ(s);
		fore(i,1,SZ(s)){
			if(s[i]!='0'){
				e=i;
				break;
			}
			a.pb(s[i]);
		}
		fore(i,e,SZ(s))b.pb(s[i]);
		ll n=stoll(a);
		ll m=0;
		if(SZ(b))m=stoll(b);
		if(m>n)cout<<n<<" "<<m<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
