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
const ll MAXN=5e5+5,INF=MAXN*10;

ll n,a[MAXN];

ll can(ll x,ll p){
	ll u=INF;
	for(ll i=n-1;i>=0;i--){
		//cout<<i<<": "<<((a[i]>>p)<<p)<<" "<<!((x|(a[i]&(1ll<<p)))>x)<<"\n";
		if((x|((a[i]>>p)<<p))>x)continue;
		if(i==n-1)u=i;
		if(u<=i+a[i])u=i;
	}
	return (u==0);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		ll res=0;
		for(ll i=20;i>=0;i--){
			//cout<<i<<": "<<res<<":\n";
			ll r=can(res,i);
			if(!r)res|=(1ll<<i);
			//res|=((!can(res,i))<<i);
			//cout<<!r<<" "<<res<<"\n\n";
		}
		if(res==(1ll<<21)-1)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
