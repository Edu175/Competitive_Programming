#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct solve{
	ll n,p,fg;
	vv sp;
	solve(vv a){
		n=SZ(a);
		p=n+1;
		fore(i,0,n)if(a[i]==1){p=i+1;break;}
		fg=1;
		if(p==n+1)fg=0,p=n;
		sp={0};
		fore(i,p,n)sp.pb(sp.back()+a[i]);
	};
	ii get(ll k){ // [,)
		ll sum=sp.back();
		if(k<=sum+fg){
			ll l=p;
			ll r=upper_bound(ALL(sp),k)-sp.begin()-1;
			// cout<<"get "<<k<<": "<<r<<": "<<sp[r]<<" "<<fg<<endl;
			if(sp[r]<k)l--,assert(sp[r]==k-fg);
			r+=p;
			return {l,r};
		}
		if((sum+fg)%2==k%2){ // meter sample 2222 TTT
			ll nec=(k-sum-fg)/2;
			ll r=n,l=p-fg-nec;
			return {l,r};
		}
		return {-1,-1};
	}
};

int main(){
	JET
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	vector<solve> dat;
	vv a;
	for(auto i:s){
		if(i=='W')a.pb(1);
		else a.pb(2);
	}
	dat.pb(a);
	reverse(ALL(a));
	dat.pb(a);
	while(q--){
		ll k; cin>>k;
		auto [l,r]=dat[0].get(k);
		if(l<0){
			auto [l,r]=dat[1].get(k);
			if(l<0)cout<<"NIE\n";
			else {
				r--;
				l=n-1-l; r=n-1-r;
				swap(l,r);
				cout<<l+1<<" "<<r+1<<"\n";
			}
		}
		else {
			cout<<l+1<<" "<<r<<"\n";
		}
	}
	return 0;
}

// get 5: 0: 0 1
// a: h.cpp:33: ii solve::get(ll): Assertion `sp[r]==k-fg' failed.
