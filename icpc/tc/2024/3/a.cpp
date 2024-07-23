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
// typedef long double ld;

int main(){JET
	ll n,a,b; cin>>n>>a>>b; //cout<<a<<" "<<b<<" a b\n";
	auto transf=[&](ii p)->ii{
		auto [x,y]=p;
		// cout<<"transf "<<x<<","<<y<<": "<<x-a*y<<","<<x*a+y<<"\n";
		return {x+a*y,-x*a+y};
	};
	// transf({1,0});
	map<ll,ll>bu;
	map<ii,ll>ig;
	vector<ii>ps;
	fore(i,0,n){
		ll x; cin>>x;
		ii p;
		cin>>p.fst>>p.snd;
		p=transf(p);
		bu[p.snd]++;
		ig[p]++;
		ps.pb(p);
	}
	ll res=0;
	for(auto p:ps){
		// cout<<p.fst<<","<<p.snd<<": "<<bu[p.snd]<<"-"<<ig[p]<<" = "<<bu[p.snd]-ig[p]<<"\n";
		res+=bu[p.snd]-ig[p];
	}
	cout<<res<<"\n";
	return 0;
}