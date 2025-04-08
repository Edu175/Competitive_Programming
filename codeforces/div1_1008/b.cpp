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
ll B=30;
ll ask(ll n){
	cout<<n<<endl;
	assert(n<(1ll<<30));
	ll ret; cin>>ret;
	fore(i,0,B)if((n>>i&1))ret-=2ll<<i;
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m0=0,m1=0;
		fore(i,0,B){
			if(i&1)m1|=1ll<<i;
			else m0|=1ll<<i;
		}swap(m0,m1);
		vv v(B);
		ll mk=ask(m0);
		for(ll i=0;i<B;i+=2)v[i]=mk>>i&3;
		// cout<<mk<<"\n";
		// imp(v)
		mk=ask(m1);
		for(ll i=1;i<B;i+=2)v[i]=mk>>i&3;
		// cout<<"pinga";
		// cout<<endl;
		fore(i,0,B)assert(v[i]<3);
		cout<<"!"<<endl;
		ll m; cin>>m;
		ll res=0;
		fore(i,0,B){
			ll h=2;
			if(!(m>>i&1))h=v[i];
			res+=h<<i;
		}
		cout<<res<<endl;
	}
	return 0;
}
