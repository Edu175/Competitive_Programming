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
		ll n; cin>>n;
		ll did=0;
		vv a;
		fore(i,0,n){
			ll x; cin>>x;
			if(!did||x)a.pb(x);
			did|=!x;
		}
		n=SZ(a);
		ll res=SZ(a)-1;
		ll flag=1;
		multiset<ll>l,r; ll mex=0;
		fore(i,0,n)l.insert(a[i]);
		for(ll i=n-1;i>=1;i--){
			r.insert(a[i]);
			l.erase(l.find(a[i]));
			while(r.count(mex))mex++;
			flag&=*l.begin()>=mex;
		}
		cout<<res+flag<<"\n";
	}
	return 0;
}
