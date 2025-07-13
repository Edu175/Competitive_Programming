#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll dig(ll n){
	ll res=0;
	while(n>0)res++,n/=10;
	return res;
}
ll pot(ll d, ll b, ll bo){
	ll p=1;
	while(dig(p)<d)p*=b;
	if(bo){
		while(dig(p)<=d)p*=b;
		p/=b;
	}
	return p;
}
ii sv(ll a, ll b, ll bo){
	ll x=pot(a,2,bo);
	ll y=pot(b,3,bo);
	return {x,y};
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c; cin>>a>>b>>c;
		ll bo=-1,x=-1;
		fore(i,0,min(a,b))fore(j,0,2){
			if(a+b-i-1+j==c)x=i,bo=j;
		}
		if(bo==-1)cout<<"No\n";
		else {
			cout<<"Yes\n";
			auto [u,v]=sv(a-x,b-x,bo);
			fore(i,0,x)u*=10,v*=10;
			assert(dig(u)==a);
			assert(dig(v)==b);
			assert(dig(lcm(u,v))==c);
			cout<<u<<" "<<v<<"\n";
		}
	}
	return 0;
}
