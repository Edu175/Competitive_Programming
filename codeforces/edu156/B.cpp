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
typedef long double ld;
typedef pair<ll,ll> ii;

ld dis(ii a, ii b){
	return sqrt((a.fst-b.fst)*(a.fst-b.fst)+(a.snd-b.snd)*(a.snd-b.snd));
}

ii a,b,p,o;
bool can(ld w){
	if(dis(a,p)<=w&&dis(a,o)<=w)return 1;
	if(dis(b,p)<=w&&dis(b,o)<=w)return 1;
	if(dis(a,b)<=2*w){
		if(dis(a,o)<=w&&dis(b,p)<=w)return 1;
		if(dis(b,o)<=w&&dis(a,p)<=w)return 1;
	}
	return 0;
}

int main(){FIN;
	o={0,0};
	ll t; cin>>t;
	while(t--){
		cin>>p.fst>>p.snd>>a.fst>>a.snd>>b.fst>>b.snd;
		ld l=0,r=1e4;
		ll it=100;
		while(it--){
			ld m=(l+r)/2;
			if(can(m))r=m;
			else l=m;
		}
		cout<<fixed<<setprecision(15);
		cout<<l<<"\n";
	}
	return 0;
}
