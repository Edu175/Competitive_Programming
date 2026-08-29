#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// random_device rd;
mt19937 rng(2315);
ll read(){
	ll x; cin>>x;
	if(x==-1)exit(0);
	return x;
}
const ll B=30,all=(1ll<<B)-1;
ll neg(ll x){return x^all;}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		// cerr<<"new test\n";
		ll x=1;
		cout<<x<<endl;
		ll got=read();
		vv ms{0,ll(rng()&all)|1};
		if(got!=x)ms={0,all};
		cout<<ms[0]<<" "<<ms[1]<<endl;
		ll xr=read();
		vv cand;
		vv ids;
		ll id=0;
		for(auto m:ms){
			ll v=m^xr;
			if((v|x)==got||(v&x)==got)cand.pb(v),ids.pb(id);
			id++;
		}
		assert(SZ(cand));
		if(got!=x)assert(SZ(cand)==1);
		else if(SZ(cand)==2){
			assert(cand[0]%2!=cand[1]%2);
			if(cand[0]%2){
				swap(cand[0],cand[1]);
				swap(ids[0],ids[1]);
			}
		}
		else assert(cand[0]%2);
		cout<<ids[0]<<endl;
	}
	return 0;
}
