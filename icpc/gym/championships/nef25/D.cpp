#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size()) 
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vector<queue<ll>> a(n);
	vv s(n),e(n); // s is dynamic
	vv sum(n);
	ll mxs=0;
	multiset<ll> ms;
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	auto val=[&](ll i){return e[i]-sum[i];}; // min r
	fore(i,0,n){
		a[i].push(0);
		ll k; cin>>k>>s[i]>>e[i];
		mxs=max(mxs,s[i]);
		fore(_,0,k){
			ll l; cin>>l;
			a[i].push(l);
			sum[i]+=l;
		}
		ms.insert(val(i));
		pq.push({s[i]+a[i].front(),i});
	}
	ll res=0;
	while(SZ(pq)){
		auto [pos,i]=pq.top(); pq.pop();
		ms.erase(ms.find(val(i)));
		ll x=a[i].front(); a[i].pop();
		s[i]+=x;
		sum[i]-=x;
		ms.insert(val(i));
		if(SZ(a[i]))pq.push({s[i]+a[i].front(),i});
		if(pos>=mxs){
			assert(SZ(ms));
			if(1){
				ll cur=*ms.begin()-pos;
				res=max(res,cur);
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
