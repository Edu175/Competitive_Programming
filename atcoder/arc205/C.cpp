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
const ll INF=1e18;
bool get(vector<pair<ii,ll>> &a, ll rev){ // all same direction
	if(rev)for(auto &i:a){
		i.fst.fst*=-1,i.fst.snd*=-1;
		swap(i.fst.fst,i.fst.snd);
	}
	
	sort(ALL(a));
	// cerr<<"get ";
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	ll R=-INF;
	for(auto [fst,snd]:a){
		auto [l,r]=fst;
		if(r<=R)return 0;
		R=r;
	}
	return 1;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ii,ll>> a,b;
	fore(i,0,n){
		ll l,r; cin>>l>>r;
		(l<r?a:b).pb({{l,r},i});
	}
	auto r0=get(a,0);
	auto r1=get(b,1);
	ll fg=(r0&&r1);
	// cerr<<r0<<" "<<r1<<"\n";
	if(fg){
		auto doit=[&](vector<ii> a, vector<ii> b){
			for(auto [l,r]:a){
				auto ptr=upper_bound(ALL(b),ii({-l,INF}));
				if(ptr!=b.begin()){
					auto [s,e]=*prev(ptr);
					// cout<<-l<<": "<<s<<","<<e<<"\n";
					if(-l<=e)return 0;
				}
			}
			return 1;
		};
		vector<ii>A,B;
		for(auto i:a)A.pb(i.fst);
		for(auto i:b)B.pb(i.fst);
		fg&=doit(A,B);
		fg&=doit(B,A);
	}
	if(fg){
		cout<<"Yes\n";
		reverse(ALL(a));
		reverse(ALL(b));
		for(auto i:a)cout<<i.snd+1<<" ";;
		for(auto i:b)cout<<i.snd+1<<" ";;
		cout<<"\n";
	}
	else cout<<"No\n";
	return 0;
}
