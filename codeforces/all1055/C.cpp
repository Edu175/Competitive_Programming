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
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv b(n-1);
		fore(i,0,n-1)b[i]=a[i]==a[i+1];
		vv sp(n);
		fore(i,1,n)sp[i]=sp[i-1]+b[i-1];
		vv sa(n+1);
		fore(i,1,n+1)sa[i]=sa[i-1]+a[i-1];
		while(q--){
			ll l,r; cin>>l>>r; l--,r--;
			ll c=sp[r]-sp[l];
			ll u=sa[r+1]-sa[l];
			ll z=r-l+1;
			if(u%3||(z-u)%3){
				cout<<"-1\n";
				continue;
			}
			assert(z%3==0);
			ll res=z/3;
			res+=c==0;
			cout<<res<<"\n";
		}
	}
	return 0;
}
