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

int main(){FIN;
	ll n,s; cin>>n>>s;
	vector<vector<ii>> a(2);
	fore(i,0,n){
		ll x,ty; cin>>x>>ty;
		a[ty].pb({x,i});
	}
	vector<vv> sps(2);
	fore(ty,0,2){
		auto &v=a[ty];
		sort(ALL(v));
		reverse(ALL(v));
		ll s=0;
		auto &sp=sps[ty];
		sp.pb(s);
		for(auto i:v)s+=i.fst,sp.pb(s);
	}
	ii res={n+5,n+5};
	fore(c,0,SZ(sps[1])){
		ll ten=sps[1][c];
		ll ned=s-ten;
		auto &otr=sps[0];
		ll k=lower_bound(ALL(otr),ned)-otr.begin();
		if(k>=SZ(otr))continue;
		ii cur={k+c,-c}; // xd lei minima
		res=min(res,cur);
	}
	auto [t,c]=res; c=-c;
	assert(t<=n);
	cout<<t<<" "<<c<<"\n";
	ll k=t-c;
	fore(i,0,k)cout<<a[0][i].snd+1<<" ";
	fore(i,0,c)cout<<a[1][i].snd+1<<" ";
	cout<<"\n";
	return 0;
}
