#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		ll p=-1;
		for(ll i=2;i*i<=x;i++)if(x%i==0){
			p=i;
			break;
		}
		ll res=x-1;
		if(p!=-1&&p<x){
			ll g=p/x;
			ll y=(x-1)/g*g;
			if(gcd(x,y)+y>x)res=y;
		}
		cout<<res<<"\n";
	}
	return 0;
}
