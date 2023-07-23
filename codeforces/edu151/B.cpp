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
		ii a,b,c; cin>>a.fst>>a.snd>>b.fst>>b.snd>>c.fst>>c.snd;
		ll res=0;
		if((a.fst-b.fst<0)==(a.fst-c.fst<0))
			res+=min(abs(a.fst-b.fst),abs(a.fst-c.fst));
		if((a.snd-b.snd<0)==(a.snd-c.snd<0))
			res+=min(abs(a.snd-b.snd),abs(a.snd-c.snd));
		cout<<res+1<<"\n";
	}
	return 0;
}
