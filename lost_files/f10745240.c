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
	ll res=sqrt(x)-3;
	fore(i,0,5){
		res++;
		if(res<0)continue;
		if(res*res>x){
			res--;
			break;
		}
	}
	return res;
}
bool is_sq(ll x){
	return (fsqrt(x)*fsqrt(x)==x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll k=__builtin_ctzll(n);
		n>>=k;
		ll a=-1,b=-1;
		for(ll i=0;i*i<=n;i++){
			if(is_sq(n-(i*i))){
				a=i;
				b=fsqrt(n-(i*i));
				break;
			}
		}
		if(a==-1){
			cout<<"-1\n";
			continue;
		}
		a*=1ll<<(k/2);
		b*=1ll<<(k/2);
		if(k&1){
			if(a>b)swap(a,b);
			ll ai=a+b,bi=b-a;
			a=ai,b=bi;
		}
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

