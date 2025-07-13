#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool good(ii s, ii t, ii d){
	ii a={t.fst-s.fst,t.snd-s.snd};
	return (abs(a.fst)==abs(a.snd)&&
		(a.fst<0)==(d.fst<0)&&(a.snd<0)==(d.snd<0));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,s; cin>>n>>s;
		vector<ii> edg={{0,0},{0,s},{s,0},{s,s}};
		ll res=0;
		fore(i,0,n){
			ll fg=0;
			ii a,d; cin>>d.fst>>d.snd>>a.fst>>a.snd;
			for(auto t:edg)fg|=good(a,t,d);
			res+=fg;
		}
		cout<<res<<"\n";
	}
	return 0;
}
