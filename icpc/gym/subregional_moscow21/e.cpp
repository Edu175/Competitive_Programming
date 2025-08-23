#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ppc(ll n){return __builtin_popcountll(n);}

#define bint __int128
const ll D=19;
int main(){
	JET
	ll pot[D];
	pot[0]=1;
	fore(i,1,D)pot[i]=pot[i-1]*10;
	map<ll,ll>mp;
	fore(mk,2,1ll<<10)fore(d,0,D){
		vv p;
		fore(i,0,10)if(mk>>i&1)p.pb(i);
		if(d<SZ(p))continue;
		string s;
		if(p[0]==0){
			s.pb(p[1]);
			fore(_,0,d-SZ(p)+1)s.pb(0);
			fore(j,2,SZ(p))s.pb(p[j]);
		}
		else {
			fore(_,0,d-SZ(p)+1)s.pb(p[0]);
			fore(j,1,SZ(p))s.pb(p[j]);
		}
		for(auto &i:s)i+='0';
		ll g=0,num=0;
		num=stoll(s); g=num;
		fore(a,0,SZ(p))fore(b,a+1,SZ(p)){
			// if(num==48){
			// 	cout<<p[a]<<","<<p[b]<<" "<<pot[i]<<","<<pot[j]<<": "<<(pot[i]-pot[j])*(p[a]-p[b])<<"\n";
			// }
			g=gcd(g,9*(p[a]-p[b]));
		}
		if(!mp.count(g))mp[g]=num;
		else mp[g]=min(mp[g],num);
		// if(num==48){
		// 	cout<<mk<<" "<<d<<": "<<num<<" "<<g<<"\n";
		// }
	}
	for(auto [k,num]:mp)cout<<k<<": "<<num<<"\n";
	return 0;
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		if(!mp.count(n))cout<<"-1\n";
		else cout<<mp[n]<<"\n";
	}
}


/*

1: 1
2: 2
3: 3
4: 4
5: 5
6: 6
7: 7
8: 8
9: 9
11: 11
12: 48
18: 468
22: 22
27: 6669
33: 33
36: 44444448
44: 44
55: 55
66: 66
77: 77
88: 88
99: 99


*/