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
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		map<ll,ll> cant;
		ll h=0;
		ll res=0;
		ll n; cin>>n;
		fore(r,0,n+1){
			ll tot=r*(r+1)/2;
			ll c=cant[h];
			ll cur=tot-c*(c+1)/2;
			// cout<<r<<": "<<tot<<" "<<cant[h]<<": "<<cur<<"\n";
			res+=cur;
			cant[h]++;
			if(r<n){
				ll x; cin>>x;
				h^=x;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
