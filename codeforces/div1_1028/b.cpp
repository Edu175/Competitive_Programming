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
		ll n,q; cin>>n>>q;
		vv b(n);
		fore(i,0,n)cin>>b[i];
		vector<array<ll,3>> qs(q);
		fore(i,0,q){
			ll x,y,z; cin>>x>>y>>z; x--,y--,z--;
			qs[i]={x,y,z};
		}
		vv a=b;
		reverse(ALL(qs));
		
		for(auto [x,y,z]:qs){
			ll v=a[z];
			a[z]=0;
			a[x]=max(a[x],v);
			a[y]=max(a[y],v);
			// imp(a)
		}
		
		vv c=a;
		reverse(ALL(qs));
		for(auto [x,y,z]:qs){
			c[z]=min(c[x],c[y]);
		}
		// cout<<"final\n";
		// imp(a)
		// imp(c)
		if(c!=b)cout<<"-1\n";
		else {
			imp(a)
		}
		
	}
	return 0;
}
