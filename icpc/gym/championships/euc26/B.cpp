#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vector<ii> get(ll n){
	vv a;
	ll q=0;
	fore(i,0,n){
		q++;
		char c='1';
		if(i<n-1)cin>>c;
		if(c=='1')a.pb(q),q=0;
	}
	sort(ALL(a));
	vector<ii> ret;
	for(auto i:a){
		if(SZ(ret)&&ret.back().fst==i)ret.back().snd++;
		else ret.pb({i,1});
	}
	return ret;
}

int main(){
	JET
	ll n; cin>>n;
	auto a=get(n);
	auto b=get(n);
	assert(max(SZ(a),SZ(b))<=5000);
	ll res=0;
	for(auto [va,ca]:a)for(auto [vb,cb]:b){
		ca&=1,cb&=1;
		ll x=va*vb;
		if(ca&&cb)res^=x;
	}
	cout<<res<<"\n";
	return 0;
}