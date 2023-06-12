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
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		vector<ll>p;
		fore(i,0,n){
			fore(j,i+1,n){
				ll b=a[i],c=a[j]; if(b>c)swap(b,c);
				ll d=c-b;
				for(ll x=1;x*x<=d;x++){
					if(d%x!=0)continue;
					ll a0=(d-x*(x-1))/x;
					if((a0-1)%2||a0<=0)continue;
					ll q=(a0-1)/2;
					p.pb(q*q-b);
				}
			}
		}
		ll res=1;
		for(auto x:p){
			if(x<0||x>1e18)continue;
			ll resi=0;
			fore(i,0,n){
				ll r=fsqrt(a[i]+x);
				resi+=(r*r==a[i]+x);
			}
			res=max(resi,res);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
