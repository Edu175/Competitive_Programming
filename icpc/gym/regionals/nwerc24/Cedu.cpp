#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n=5;
	vv xs,ys;
	vector<ii> a(n);
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd;
		xs.pb(a[i].fst);
		ys.pb(a[i].snd);
	}
	auto zip=[&](vv &v){sort(ALL(v)); v.resize(unique(ALL(v))-v.begin());};
	zip(xs); zip(ys);
	for(auto &[x,y]:a){
		x=lower_bound(ALL(xs),x)-xs.begin();
		y=lower_bound(ALL(ys),y)-ys.begin();
	}
	
	return 0;
}