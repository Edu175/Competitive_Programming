#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 1e5+100;
vv g[MAXN];

map<vv,ll>dp;

// 0 = can use, 1 = erased, 2 = only first, 3 = only second, 4 not discovered
enum {USE,OUT,ONLY1,ONLY2,NOTYET};

ll n;
vv go(vv a, vv us, vv ind){ // returns empty if invalid
	fore(i,0,SZ(us)){
		ll y=us[i],old=a[y];
		a[y]=OUT;
		if(old==ONLY1+ind[i])continue;
		if(old!=USE)return {};
	}
	fore(i,0,n)if(a[i]==ONLY1||a[i]==ONLY2)a[i]=USE; // proscribio
	fore(w,0,SZ(us))for(auto y:g[us[w]]){
		assert(a[y]==NOTYET);
		ll t=ind[w];
		a[y]=ONLY1+t;
	}
	return a;
}
ll f(vv a){
	if(count(ALL(a),OUT)==n)return 0; // todos sacados
	auto [it,nuevo]=dp.try_emplace(a);
	auto& res=it->second;
	if(!nuevo)return res;
	res=n+5;
	auto cand=[&](ll cur){res=min(res,cur);};
	fore(x,0,n)fore(t,0,2){
		auto b=go(a,{x},{t});
		if(!SZ(b))continue;
		cand(1+f(b));
		fore(y,x+1,n){
			auto b=go(a,{x,y},{t,t^1});
			if(!SZ(b))continue;
			cand(1+f(b));
		}
	}
	// for(auto i:a)cout<<i<<" ";;cout<<": "<<res<<"\n";
	
	return res;
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("dual.in","r",stdin);
	freopen("dual.out","w",stdout);
	#endif
	JET
	
	cin>>n;
	vv a(n,NOTYET);
	fore(i,0,n){
		ll x; cin>>x;
		x--;
		if(x>=0)g[x].pb(i);
		else a[i]=USE;
	}
	auto res=f(a);
	cout<<res<<"\n";
	
	
	return 0;
}