#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ll res=0;
	ll x=0,y=0;
	set<ii>st;
	auto simul=[&](ll q, ll dx, ll dy){
		while(q--&&!st.count({x,y}))st.insert({x,y}),x+=dx,y+=dy,res++;
	};
	fore(i,0,n){
		char c; ll q; cin>>c>>q; q*=2;
		if(c=='R')simul(q,1,0);
		if(c=='U')simul(q,0,1);
		if(c=='L')simul(q,-1,0);
		if(c=='D')simul(q,0,-1);
	}
	if(st.count({x,y}))cerr<<"choco\n";
	cout<<res/2<<"\n";
	return 0;
}
