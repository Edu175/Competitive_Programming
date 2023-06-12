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
#define bint __int128
const ll CUT=2340,D=6;
ll n;
bint fpow(bint b, ll e){
	if(e<0)return 0;
	bint ret=1;
	while(e){
		if(e&1)ret=ret*b;
		b=b*b,e>>=1;
	}
	return ret;
}
ll can(ll mk,ll b){//b**mk <= n ?
	bint x=0;
	ll ld=-1;
	fore(i,0,D)if(mk&(1ll<<i))ld=i;
	fore(i,0,ld+1){
		if(fpow(b,i)+x>n){
			x+=fpow(b,i);
			break;
		}
		if(mk&(1ll<<i))x+=fpow(b,i);
	}
	if(x>n)return 0;
	if(x<n)return 1;
	return 2;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		ll res=0;
		fore(i,2,CUT){
			ll flag=1;
			ll ni=n;
			while(ni){
				if(ni%i>1)flag=0;
				ni/=i;
			}
			res+=flag;
		}
		fore(mk,0,1ll<<D){
			ll l=2,r=n;
			while(l<=r){
				ll m=(l+r)/2;
				if(can(mk,m))l=m+1;
				else r=m-1;
			}
			res+=(r>=CUT&&can(mk,r)==2);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
