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

ll ask(ll s, vv v){
	cout<<"? "<<s+1<<" "<<SZ(v)<<" ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	ll ret; cin>>ret; ret--; // aristas
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv all(n); iota(ALL(all),0);
		vector<vv> d(n);
		fore(x,0,n)d[ask(x,all)].pb(x);
		vv res;
		ll mxd=0;
		fore(i,0,n)if(SZ(d[i]))mxd=i;
		for(ll x=d[mxd][0],i=mxd;i>=0;i--){
			res.pb(x);
			if(i){
				auto v=d[i-1];
				ll y=-1;
				for(auto i:v)if(ask(x,{x,i}))y=i;
				assert(y!=-1);
				x=y;
			}
		}
		cout<<"! "<<SZ(res)<<" ";
		for(auto i:res)cout<<i+1<<" ";
		cout<<endl;
	}
	return 0;
}
