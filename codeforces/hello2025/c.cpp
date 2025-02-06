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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll B=32;
		// ll esp=0;
		// if(__builtin_popcountll((r>>__builtin_ctzll(r))+1)==1)esp=1;
		// if(esp){
		// 	cout<<r<<" "<<l+1<<" "<<l<<"\n";
		// 	continue;
		// }
		ll apa=0,did=0,pot=-1,pot2=-1,cum=0;
		ll x=0,a=0;
		for(ll j=B-1;j>=0;j--){
			ll p=r>>j&1,q=l>>j&1;
			if(!p&&q){
				if(pot2==-1||cum){
					if(pot2==-1)pot2=1ll<<j;
					else pot2|=1<<j;
				}
				cum=1;
			}
			else cum=0;
			apa|=p;
			did|=p!=q;
			if(!apa)continue;
			if(!did)a|=p<<j;
			else {
				if(!p&&!q)x|=1ll<<j;
				if(pot==-1)pot=1ll<<j;
			}
		}
		x|=a;
		// cout<<pot<<" pot\n";
		// cout<<pot2<<" pot2\n";
		// cout<<endl;
		if(x<=l)x+=pot;
		if(x>=r)x^=pot|pot2;
		cout<<l<<" "<<r<<" "<<x<<"\n";
		// cout<<endl;
		assert(l<x&&x<r);
	}
	return 0;
}
