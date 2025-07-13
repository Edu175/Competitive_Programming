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
// #pragma optimize("O3")
int main(){FIN;
	ll n,k,q; cin>>n>>k>>q;
	vv a(n);
	multiset<ll>l,r;
	ll sum=0;
	fore(i,0,n)(i<k?l:r).insert(0);
	auto balance=[&](){
		while(SZ(l)<k){
			ll x=*r.begin();
			sum+=x;
			l.insert(x),r.erase(r.begin());
		}
	};
	auto divi=[&](){
		while(SZ(l)&&SZ(r)&&*l.rbegin()>*r.begin()){
			ll x=*l.rbegin();
			ll y=*r.begin();
			sum+=y-x;
			l.erase(l.find(x));
			r.erase(r.begin());
			l.insert(y);
			r.insert(x);
		}
	};
	fore(i,0,q){
		ll x,y; cin>>x>>y; x--; y=-y;
		bool bo=l.count(a[x]);
		auto &s=(bo?l:r);
		s.erase(s.find(a[x]));
		if(bo)sum-=a[x];
		a[x]=y;
		r.insert(a[x]);
		balance();
		divi();
		// imp(l)
		// imp(r)
		cout<<-sum<<"\n";
	}
	return 0;
}