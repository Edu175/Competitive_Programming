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

vector<ii> fact(ll x){
	vector<ii>v;
	for(ll i=2;i*i<=x;i++){
		ll c=0;
		while(x%i==0){
			c++;
			x/=i;
		}
		if(c)v.pb({i,c});
	}
	if(x>1)v.pb({x,1});
	return v;
}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll a,b; cin>>a>>b;
	vector<ii> v=fact(a);
	vector<bint>e;
	fore(i,0,SZ(v)){
		e.pb(bint(v[i].snd)*bint(b));
	}
	ll q=1;
	fore(i,0,SZ(e)){
		q=q*((e[i]+1)%MOD)%MOD;
	}
	ll res=b%MOD*q%MOD*fpow(2,MOD-2)%MOD;
	cout<<res<<"\n";
	return 0;
}
