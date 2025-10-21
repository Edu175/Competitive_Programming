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

ll n;

ll fn(ll n){return n*(n+1)/2;}
ll best(ll mx, ll c){ // (mx,mx+c]
	ll u=mx+c;
	ll res=fn(u)-fn(mx);
	return res;
}

vv can(ll s, ll k, ll dbg=0){ // empty if not possible (osea me paso)
	// if(dbg)cerr<<"can "<<k<<"\n";
	ll dep=1,c=n-1;
	queue<ll> fa,prox;
	ll left=0; // for front
	fa.push(0);
	left=k;
	vv ret;
	fore(i,1,n){
		// if(dbg)cerr<<i<<": "<<dep<<" "<<c<<"\n";
		if(s-dep<0)return {};
		assert(left>0);
		// cerr<<best(dep,c-1)+dep<<" pongo\n";
		// cerr<<SZ(fa)<<" szFa\n";
		if(best(dep,c-1)+dep<s||!SZ(fa)){
			dep++; while(SZ(fa))fa.pop();
			assert(SZ(prox));
			// if(!SZ(prox))return {}; // me quedo corto
			swap(prox,fa);
			left=k;
		}
		assert(!(best(dep,c-1)+dep<s)&&SZ(fa));
		if(s-dep<0)return {};
		ret.pb(fa.front());
		prox.push(i);
		left--;
		// if(dbg)cerr<<"dep:"<<dep<<" fa:"<<fa.front()<<"\n";
		if(!left)fa.pop(),left=k;
		s-=dep; c--;
		// if(dbg)cerr<<s<<" s\n\n";
	}
	assert(!s);
	return ret;
}

int main(){FIN;
	ll s; cin>>n>>s; s-=n;
	if(s<n-1||s>n*(n-1)/2){
		cout<<"No\n";
		return 0;
	}
	ll l=0,r=n+5;
	while(r-l>1){
		ll m=(l+r)/2;
		if(SZ(can(s,m)))r=m;
		else l=m;
	}
	ll m=r;
	auto ret=can(s,m);
	if(!SZ(ret)){
		cout<<"No\n";
		return 0;
	}
	// can(s,5,1);
	// cerr<<m<<"\n";
	cout<<"Yes\n";
	for(auto i:ret)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
