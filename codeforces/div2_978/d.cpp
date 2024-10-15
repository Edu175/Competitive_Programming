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
const ll MAXN=1e5+5;

map<ll,ll> mp[MAXN];

ll ask(ll i, ll j){
	if(mp[i].count(j))return mp[i][j];
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	ll &ret=mp[i][j]; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}
bool hay(ll l, ll r){
	// if(l==r-1)return 1;
	assert(r-l>1);
	vv h;
	fore(i,l,r)h.pb(i);
	ll p=0;
	fore(i,0,SZ(h)){
		p^=!(ask(h[i],h[(i+1)%SZ(h)]));
	}
	// cerr<<"hay "<<l<<","<<r<<": "<<p<<"\n";
	return p;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)mp[i].clear();
		ll l=1,r=n-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(hay(0,m+1))r=m-1;
			else l=m+1;
		}
		if(l==1){// 0 o 1, 2 safe
			if(ask(0,2)!=ask(2,0))l=0;
		}
		cout<<"! "<<l+1<<endl;
	}
	return 0;
}
