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
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a)); reverse(ALL(a));
		a.resize(min(SZ(a),30));
		while(q--){
			ll c; cin>>c;
			priority_queue<ll> pq;
			for(auto i:a)pq.push(i);
			ll res=0;
			for(ll j=29;j>=0;j--)if(c>>j&1){
				auto x=pq.top(); pq.pop();
				ll p=1ll<<j;
				ll d=p-x;
				res+=max(d,0ll);
				x=max(-d,0ll);
				pq.push(x);
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
