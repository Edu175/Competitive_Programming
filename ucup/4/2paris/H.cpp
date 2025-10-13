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
		ll n,d; cin>>n>>d;
		ll sum=0;
		queue<ll> q;
		vv a(n);
		fore(i,0,n){
			ll x; cin>>x;
			sum+=x;
			a[i]=x;
			q.push(i);
		}
		ll k=sum/n;
		ll mx=0;
		// cerr<<"k "<<k<<"\n";
		fore(i,0,n){
			ll c=k;
			while(c){
				auto j=q.front();
				ll u=min(c,a[j]);
				c-=u; a[j]-=u;
				if(!a[j])q.pop();
				mx=max(mx,abs(i-j));
				// cerr<<j<<" -> "<<i<<": "<<u<<"\n";
			}
		}
		// assert(!SZ(q));
		ll res=(mx+d-1)/d;
		cout<<res<<"\n";

	}
	return 0;
}
