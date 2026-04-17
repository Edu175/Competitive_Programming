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
		vv a;
		ll v=1,sig=1;
		ll mk=n&5;
		if(mk==0)v=1;
		else if(mk==1)a={0},v=1;
		else if(mk==4)a={1,-2,2,-1},v=3;
		else {assert(mk==5);a={1,-2,0,2,-1};v=3;}
		while(SZ(a)<n){
			a.pb(-v*sig);
			a.pb(v*sig);
			v++;
			if(SZ(a)>=n)break;
			a.pb(v*sig);
			a.pb(-v*sig);
			v++;
			sig*=-1;
		}
		
		// cerr<<n<<": "<<"antes "; imp(a)
		
		// comprimi a y suma 1
		vv vals(ALL(a));
		sort(ALL(vals));
		assert(unique(ALL(vals))==vals.end());
		auto get_idx=[&](ll x){return lower_bound(ALL(vals),x)-vals.begin();};
		for(auto &i:a)i=get_idx(i)+1;
		imp(a)
		// cout<<endl;
		auto check=[&](){
			ll dif3=0;
			fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n){
				if(a[i]<a[j]&&a[j]<a[k])dif3++;
				if(a[i]>a[j]&&a[j]>a[k])dif3--;
			}
			cerr<<"dif3: "<<dif3<<"\n";
			return !dif3;
		};
		
		// assert(check());
		
	}
	return 0;
}
