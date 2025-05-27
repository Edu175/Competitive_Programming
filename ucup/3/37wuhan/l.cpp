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
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll res=0; // 1
		fore(l,0,n)fore(m,l,n){
			ll v=2*a[m]-a[l];
			
			ll r=upper_bound(ALL(a),v)-a.begin()-1;
			assert(r>=0);
			if(a[r]!=v)continue;
			ll d1=r-m,d0=m-l;
			ll z=min(d0,d1);
			ll resi=2*z+1+(d1>d0);
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
