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
const ll MAXN=2e5+5;

ll fn(ll n){return n*(n+1)/2;}
ll sump(ll l, ll r){ // (,]
	return fn(r)-fn(l);
}
ll n;
vv a;
ll dame(ll sig, ll u){
	priority_queue<ii>pq;
	fore(i,0,n){
		ll val=a[i];
		if(sig==-1)val=-(val+1);
		pq.push({val,1});
	}
	ll del=0;
	// cout<<"\ndame "<<sig<<" "<<u<<"\n";
	while(u>0&&SZ(pq)){
		auto [x,q]=pq.top(); pq.pop();
		ll cant=0;
		// ll y=pq.top().fst;
		if(!SZ(pq))cant=max(x,0ll);
		else cant=x-pq.top().fst;//,cout<<pq.top().fst<<"\n";;
		// cerr<<"cant bef "<<cant<<"\n";
		cant*=q;
		cant=min(cant,u);
		u-=cant;
		assert(cant>0);
		ll h=cant/q;
		ll r=cant%q; ll s=x-h;
		ll now=sump(s,x)*q+r*s;
		
		// cout<<x<<" "<<q<<": "<<cant<<": "<<now<<"\n";
		// cout<<s<<"\n";
		del+=now;
		if(SZ(pq)){
			auto [x2,q2]=pq.top(); pq.pop();
			q2+=q;
			pq.push({x2,q2});
		}
	}
	// cout<<"= "<<del<<"\n";
	return del;
}
ll cost(ll u){ // this is convex
	ll big=-dame(1,u);
	ll small=-dame(-1,u);
	ll tot=0;
	fore(i,0,n)tot+=fn(a[i]);
	ll res=tot+(big+small);
	// cout<<"cost "<<u<<": "<<big<<" "<<small<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>k;
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a)); reverse(ALL(a));
		ll l=0,r=1e12;
		while(l<=r){
			ll m=(l+r)/2;
			ll u=m,v=m+1;
			if(cost(u)-cost(v)>k)l=m+1;
			else r=m-1;
		}
		ll u=l;
		cost(2);
		// cerr<<"l "<<l<<"\n";
		cout<<cost(u)+k*u<<"\n";
	}
	return 0;
}
