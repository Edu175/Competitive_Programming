#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ask(ll i, ll j){
	cout<<i+1<<" "<<j+1<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii> all;
		fore(i,0,n)fore(j,i+1,n)all.pb({i,j});
		sort(ALL(all),[&](ii a, ii b){return a.snd-a.fst<b.snd-b.fst;});
		for(auto p:all)if(ask(p.fst,p.snd))break;
	}
	return 0;
}