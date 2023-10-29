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

ll dis(ii a, ii b){return abs(a.fst-b.fst)+abs(a.snd-b.snd);}
ii _a,_b,_c;
ll bien(ll ax){
	ll a,b,c;
	if(ax==0){
		a=_a.fst,b=_b.fst,c=_c.fst;
	}
	else a=_a.snd,b=_b.snd,c=_c.snd;
	if((ll)0<abs(a-b)&&abs(a-b)<=abs(a-c)&&abs(a-b)+abs(b-c)==abs(a-c))return 1;
	return 0;
}

int main(){FIN;
	ii a,b,c; cin>>a.fst>>a.snd>>b.fst>>b.snd>>c.fst>>c.snd;
	_a=a,_b=b,_c=c;
	ll res=dis(b,c)+dis(a,b)-1;
	ll add=0;
	if((bien(0)&&b.snd==c.snd)||(bien(1)&&b.fst==c.fst))add=0;
	else if(bien(0)||bien(1))add=2;
	else add=4;
	//cout<<res<<" "<<add<<"\n";
	cout<<res+add<<"\n";
	return 0;
}
