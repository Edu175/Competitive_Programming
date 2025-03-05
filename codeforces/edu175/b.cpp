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
		ll n,x,k; cin>>n>>x>>k;
		string s; cin>>s;
		vv mov;
		for(auto i:s)mov.pb(i=='L'?-1:1);
		ll a=-1,b=-1;
		fore(i,0,n){
			x+=mov[i];
			if(!x){a=i+1;break;}
		}
		if(a==-1){cout<<0<<"\n";continue;}
		k-=a;
		fore(i,0,n){
			x+=mov[i];
			if(!x){b=i+1;break;}
		}
		if(b==-1){cout<<1<<"\n";continue;}
		ll res=1+k/b;
		cout<<res<<"\n";
	}
	return 0;
}
