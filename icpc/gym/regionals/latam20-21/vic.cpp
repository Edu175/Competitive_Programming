#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impr(v) {cout<<#v<<": ";for(auto [i,j]:v)cout<<i<<","<<j<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e9+5;
int main(){
	ET
	ll n,q; cin>>n>>q;
	vv a(n);
	vector<ii>baj,sub;
	ii ant={-1,-1};
	fore(i,0,n){
		cin>>a[i];
		if(a[i]!=-1){
			if(ant.fst!=-1){
				if(a[i]<ant.snd)baj.pb({ant.fst,i});
				if(a[i]>ant.snd)sub.pb({ant.fst,i});
			}
			ant={i,a[i]};
		}
	}
	// impr(sub)
	// impr(baj)
	auto can=[&](ll l, ll r)->bool{
		if(r-l<3)return 0;
		if(a[l]!=-1&&a[l+1]!=-1&&a[l+1]<a[l])return 0;
		if(a[r-1]!=-1&&a[r-2]!=-1&&a[r-2]<a[r-1])return 0;
		auto it=lower_bound(ALL(baj),ii({l,-1}));
		if(it==baj.end()||it->snd>=r)return 1;
		ll p=it->snd;
		it=lower_bound(ALL(sub),ii({p,-1}));
		return it==sub.end()||it->snd>=r;
	};
	while(q--){
		ll l,r; cin>>l>>r;
		cout<<can(l,r)<<"\n";
	}
}