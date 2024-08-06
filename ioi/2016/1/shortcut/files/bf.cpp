#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkfjhg:v)cout<<dkfjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e16;
ll n,c;
vector<ll>p,d;
ll fake=21;
ii operator^(ii a, ii b){
	return {max(a.fst,b.fst),min(a.snd,b.snd)};
}
ll dis(ll i, ll j){
	return d[i]+d[j]+abs(p[i]-p[j]);
}
bool can(ll m){
	vector<ii>ed;
	fore(i,0,n)fore(j,i+1,n)if(dis(i,j)>m)ed.pb({i,j});
	if(!SZ(ed))return 1;
	ii par=ed[0];
	for(auto i:ed)par=par^i;
	// if(m==fake){
	// 	for(auto [i,j]:ed)cout<<i<<","<<j<<" ";;cout<<"\n";
	// }
	if(par.snd-par.fst<=0)return 0;
	
	fore(L,0,n)fore(R,L+1,n){
		ll flag=1;
		for(auto [i,j]:ed){
			if(abs(p[L]-p[i])+abs(p[R]-p[j])+d[i]+d[j]+c>m){flag=0;break;}
		}
		// if(l<=r&&m==fake){
		// 	cout<<L<<": "<<l<<","<<r<<"\n";
		// }
		if(flag)return 1;
	}
	return 0;
}
long long find_shortcut(int N, std::vector <int> L, std::vector <int> D, int C){
	n=N,c=C;
	vector<ll>a;
	for(auto i:L)a.pb(i);
	for(auto i:D)d.pb(i);
	
	p=vector<ll>(n);
	fore(i,1,n)p[i]=p[i-1]+a[i-1];
	
	ll l=0,r=INF;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	return l;
}
