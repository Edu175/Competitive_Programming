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
const ll INF=100;
ll ctz(ll x){return __builtin_ctzll(x);}
ll ppc(ll x){return __builtin_popcountll(x);}

ll num(ll x){
	if(!x)return INF;
	return ctz(x)-ctz(x+1); // #0s - #1s
}
void impr(priority_queue<ii> pq){
	while(SZ(pq)){
		auto x=pq.top(); pq.pop();
		cout<<x.fst<<","<<x.snd<<" ";
	}
	cout<<"\n";
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		priority_queue<ii>pq;
		ll res=0;
		vv a(n);
		auto add=[&](ll x){pq.push({num(x),x});};
		fore(i,0,n)cin>>a[i],res+=ppc(a[i]),add(a[i]);
		ll ans=res;
		while(k>0){
			// cout<<res<<": ";
			// impr(pq);
			auto [q,x]=pq.top(); pq.pop();
			if(q<0){ // fast forward
				ans=max(ans,res);
				res+=q;
				x++;
				ll c=-q;
				ll p=1ll<<c;
				if(k<p)break;
				k-=p;
				res+=c+1;
				x+=p-1;
			}
			else {
				x+=1; k--;
				res++;
			}
			add(x);
		}
		ans=max(ans,res);
		cout<<ans<<"\n";
	}
	return 0;
}
