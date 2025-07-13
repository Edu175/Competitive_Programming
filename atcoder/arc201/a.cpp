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
		ll A=0,B=0,C=0;
		ll res=0;
		fore(i,0,n){
			ll a,b,c; cin>>a>>b>>c;
			// cout<<a<<" "<<b<<" "<<c;
			ll Ai=max(0ll,min(a,b-c));
			ll Ci=max(0ll,min(c,b-a));
			A+=Ai,C+=Ci;
			a-=Ai,b-=Ai;
			c-=Ci,b-=Ci;
			// cout<<": "<<a<<" "<<b<<" "<<c<<endl;
			// assert(a==c);
			B+=min({a,b,c});
		}
		// cout<<A<<" "<<B<<" "<<C<<": "<<res<<"\n";
		ll q=min(A,C); res+=q; A-=q,C-=q;
		ll S=max(A,C);
		q=min(B,S); res+=q; B-=q,S-=q;
		res+=B/2;
		cout<<res<<"\n";
	}
	return 0;
}
