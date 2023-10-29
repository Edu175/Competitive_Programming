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
#define bint __int128
const ll MOD=998244353;

vector<pair<ll,ll>> fact(ll x){
	vector<ii>v;
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v.pb({i,count});
	}
	if(x>1)v.pb({x,1});
	return v;
}
ll log(ll b, bint x){
	ll ret=0;
	while(x>=b)x/=b,ret++;
	return ret;
}
ll fpow(bint b, ll e, ll lg){
	ll res=0,coef=1;
	while(e){
		if(e&1){
			res=(res+log(lg,b)*coef)%MOD;
		}
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
int main(){FIN;
	ll a,b; cin>>a>>b;
	vector<ii> v=fact(a);
	ll is_sq=1;
	for(auto i:v)if(i.snd&1)is_sq=0;
	vector<bint>e;
	fore(i,0,SZ(v)){
		e.pb(bint(v[i].snd)*bint(b));
	}
	bint q=1;
	ll lg=0;
	ll res=0;
	fore(i,0,SZ(e)){
		q*=(e[i]+1);
		while(q>=a)q/=a,lg++;
	}
	res=(lg*b%MOD);
	
	cout<<res<<"\n";
	return 0;
}
