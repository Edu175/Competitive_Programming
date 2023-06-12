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

ll logb(ll x,ll b){
	return log(x)/log(b);
}

ll fac(ll b,ll x){
	ll res=0;
	while(x%b==0)res++,x/=b;
	return res;
}
ll pot(ll b,ll e){
	ll res=1;
	fore(i,0,e)res*=b;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll f2=fac(2,n),f5=fac(5,n);
		ll b;
		if(f2<=f5)b=2;
		else b=5;
		ll d=abs(f2-f5);
		ll mi;
		if(pot(b,d)<=m)mi=pot(b,d);
		else mi=pot(b,floor(logb(m,b)));
		mi*=pot(10,floor(logb(m/mi,10)));
		mi*=m/mi;
		cout<<n*mi<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
