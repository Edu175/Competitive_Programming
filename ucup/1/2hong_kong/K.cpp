#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv a, divs;

void get_div(ll x){
	for(ll i = 1; i*i<=x;i++){
		if(x%i == 0){
			divs.pb(i);
			if(i*i != x)divs.pb(x/i);
		}
	}
}

bool can(ll x){
	if(a[0] < x) return false;
	auto it = lower_bound(ALL(a),2*x);
	if(it == a.begin()) return true;
	it--;
	return *it == x;
}

int main(){
	JET
	ll n; cin>>n;
	a.resize(n);
	fore(i,0,n) cin>>a[i];
	sort(ALL(a));
	ll x = a[0];
	get_div(x);
	ll cand = -1;
	for(auto y:divs)if(can(y))cand = max(cand,y);
	assert((x-1)/2 <= cand || (x&1));
	cout<<max(cand,(x-1)/2)<<"\n";
	return 0;
}