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
const ll MOD=998244353,MAXK=5e5+5;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll cut(ll x){return x<MOD?x:x-MOD;}
ll pot[MAXK];
ll pn;
ll f(ll n, ll k, ll p){
	ll res=1;
	fore(j,0,k){
		ll q=cut(pn-pot[j]+MOD);
		res=res*q%MOD*q%MOD*fpow(cut(pot[k]-pot[j]+MOD),MOD-2)%MOD;
	}
	return res;
}

int main(){FIN;
	ll n,k,p; cin>>n>>p>>k;
	pn=fpow(p,n);
	pot[0]=1;
	fore(i,1,k+1)pot[i]=pot[i-1]*p%MOD;
	fore(r,0,k+1){
		cout<<f(n,r,p)<<" ";
	}
	cout<<"\n";
	return 0;
}
