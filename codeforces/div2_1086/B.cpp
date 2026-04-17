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
		ll n,k,p,m; cin>>n>>k>>p>>m; p--;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		auto play=[&](ll i){
			ll v=a[i];
			a.erase(a.begin()+i);
			a.pb(v);
		};
		ll res=0;
		while(1){
			if(p<k){
				m-=a[p];
				if(m<0)break;
				res++;
				play(p);
				p=n-1;
			}
			else {
				ll mn=0;
				fore(i,0,k)if(a[i]<a[mn])mn=i;
				m-=a[mn];
				if(m<0)break;
				play(mn);
				p--;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
