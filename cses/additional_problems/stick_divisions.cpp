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
	ll sdsdfn,n; cin>>sdsdfn>>n;
	priority_queue<ll>pq;
	fore(i,0,n){
		ll x; cin>>x;
		pq.push(-x);
	}
	ll res=0;
	while(SZ(pq)>1){
		auto x=pq.top(); pq.pop(); x=-x;
		auto y=pq.top(); pq.pop(); y=-y;
		res+=x+y;
		pq.push(-(x+y));
	}
	cout<<res<<"\n";
	return 0;
}