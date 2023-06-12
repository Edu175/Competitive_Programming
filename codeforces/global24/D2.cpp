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

ll f(ll n,ll p){
	ll res=1;
	fore(i,1,n+1)res=(res*i)%p;
	return res;
}
ll fpow(ll b, ll e, ll MOD){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll n,p; cin>>n>>p;
	ll t=0,e=0;
	fore(i,0,n){
		fore(j,0,n){
			if(i==j)continue;
			ll d=abs(j-i);
			d=min(d,n-d);
			if(n%2==0&&d==n/2){
				e=(e+n-2)%p;
				//cout<<i<<" "<<j<<": 0 "<<(e+n-2)%p<<"\n";
				continue;
			}
			if(n&1)t=(t+d)%p;//,cout<<i<<" "<<j<<": "<<d<<"\n";
			else t=(t+d-1)%p;//,e=(e+2)%p,cout<<i<<" "<<j<<": "<<d-1<<" "<<2<<"\n";
		}
	}
	cout<<t<<" "<<e<<"\n";
	t=(t*fpow(6,p-2,p))%p;
	e=(e*fpow(6,p-2,p))%p;
	cout<<t<<" "<<e<<"\n";
	//if(n%2==0)assert(e==(n/2)*(n-2));
	ll ct=(t*3)%p,ce=(e*4)%p;
	cout<<ct<<" "<<ce<<" "<<f(n-3,p)<<"\n";
	ll res=((ct*f(n-3,p))%p+(ce*f(n-3,p))%p)%p;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
