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

ll ask(vv a){
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<i+1<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

bool estan(vv a){
	ll k=SZ(a);
	ll r=ask(a);
	return (k-r)&1;
}
vv rango(ll l, ll r){
	vv a(r-l); iota(ALL(a),l);
	return a;
}
int main(){
	// FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; n=2*n+1;
		vv ans;
		fore(_,0,2){
			ll l=0,r=n+1;
			while(r-l>1){
				ll m=(l+r)/2;
				auto v=rango(0,m);
				if(_){
					for(auto &i:v)i=n-1-i;
				}
				if(estan(v))r=m;
				else l=m;
			}
			ll id=r-1;
			if(_)id=n-1-id;
			ans.pb(id);
		}
		sort(ALL(ans));
		ll l=ans[0],r=ans[1];
		while(r-l>1){
			ll m=(l+r)/2;
			auto v=rango(ans[0],m);
			assert(!count(ALL(v),ans[1]));
			v.pb(ans[1]);
			if(estan(v))r=m;
			else l=m;
		}
		ans.pb(r-1);
		cout<<"! ";
		for(auto i:ans)cout<<i+1<<" ";
		cout<<endl;
	}
	return 0;
}
