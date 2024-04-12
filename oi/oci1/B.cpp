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
const ll INF=1e9+10,MAXV=1e6+5;

ll compuesto[MAXV],sp[MAXV];
const ll MOD=1e9+7;
ll fpow(ll b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=r*b%MOD;
		e>>=1; b=b*b%MOD;
	}
	return r;
}
int main(){FIN;
	ll n; cin>>n;
	ll p=1;
	fore(i,0,n){
		ll x; cin>>x;
		p=min(lcm(p,x),INF);
	}
	compuesto[0]=compuesto[1]=1;
	fore(i,2,MAXV)if(!compuesto[i])for(ll j=1ll*i*i;j<MAXV;j+=i)compuesto[j]=1;
	fore(i,1,MAXV)sp[i]=sp[i-1]+!compuesto[i-1];
	ll q; cin>>q;
	while(q--){
		ll l,r,k; cin>>l>>r>>k; r++;
		ll z=sp[r]-sp[l];
		ll b=k/p;
		cout<<(fpow(b+1,z)-1+MOD)%MOD<<"\n";
	}
	return 0;
}
