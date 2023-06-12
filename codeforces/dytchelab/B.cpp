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

ll fsqrt(ll x){
	ll sq=sqrt(x)-3;
	fore(i,0,6){
		//cout<<sq<<"\n";
		if(sq<0){
			sq++;
			continue;
		}
		if(sq*sq>x)break;
		sq++;
	}
	sq--;
	return sq;
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll res=0;
		ll sqr=fsqrt(r),sql=fsqrt(l-1);
		//cout<<sql<<" "<<sqr<<"\n";
		res+=(sqr-sql-1)*3;
		for(ll i=sqr*sqr;i<=r;i+=sqr)res++;
		if(sql)for(ll i=sql*sql;i<(sql+1)*(sql+1);i+=sql)if(i>=l)res++;
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
