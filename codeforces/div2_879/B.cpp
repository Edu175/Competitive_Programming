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
		string s,r; cin>>s>>r;
		string l(SZ(r)-SZ(s),'0');
		for(auto i:s)l.pb(i);
		ll res=0;
		//cout<<l<<" "<<r<<":\n";
		fore(i,0,SZ(r)){
			if(l[i]==r[i])continue;
			//cout<<i<<"\n";
			res+=(SZ(r)-1-i)*9+r[i]-l[i];
			break;
		}
		cout<<res<<"\n";
	}
	return 0;
}
