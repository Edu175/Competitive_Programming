#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// const ll MAXN=5005;

ll hsh(ii a){return (a.fst<<20)|a.snd;}
unordered_map<ll,ll> dp;
// ll dp[MAXN][MAXN];
ll fun(ll v, ll f);
ll calc_b(ll v, ll f, ll b){
	ll yes=fun(b,v);
	ll no= fun(f-b+v,0);
	ll cur=max(yes,no)+1;
	return cur;
}
bool in(ll x, ll l, ll r){return l<=x&&x<=r;}
ll maxd=0;
ll fun(ll v, ll f){
	if(clock()%ll(CLOCKS_PER_SEC*2)==0){
		cerr<<SZ(dp)<<" sz\n";	
	}
	ll key=hsh({v,f});
	if(dp.count(key))return dp[key];
	// cerr<<"call "<<v<<","<<f<<"\n";
	// auto &res=dp[v][f];
	// if(res!=-1)return res;
	auto &res=dp[key];
	if(v+f<=2)res=0;
	else if(!f)res=max(fun((v+1)/2,v/2),fun(v/2,(v+1)/2))+1;
	else {
		res=100000;
		fore(b,1,f+1){ // b son los de yes
			ll cur=calc_b(v,f,b);
			res=min(res,cur);
			// cerr<<"term "<<v<<","<<f<<": "<<b<<": "<<b<<","<<v<<" "<<f-b+v<<",0: "<<yes<<" "<<no<<": "<<cur<<"\n";
		}
		ll l=-1,r=-1;
		fore(b,1,f+1){
			if(calc_b(v,f,b)==res){
				if(l==-1)l=b;
				r=b;
			}
		}
		assert(l!=-1);
		// cerr<<v<<" "<<f<<": "<<(l+r)/2<<"\n";
		// cerr<<v<<" "<<f<<": "<<r<<"\n";
		// vv hs={f-v/(__lg(v)+2)};
		// vv hs={(v+f)/2,f/2,f*2/3};
		// ll mind=1e18;
		// for(auto h:hs){
		// 	ll d=min(abs(l-h),abs(r-h));
		// 	if(in(h,l,r))d=0;
		// 	mind=min(mind,d);
		// }
		// maxd=max(mind,maxd);
		// if(mind>=23){
			// cerr<<v<<" "<<f<<": "<<l<<" "<<r<<" peor\n";
		// }
		// assert(in(f/2,l,r)||in((f+1)/2,l,r));
	}
	// cerr<<"fun "<<v<<","<<f<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	// mset(dp,-1);
	// while(1){
	// 	ll v,f; cin>>v>>f;
	// 	cerr<<fun(v,f)<<"\n";
	// 	dp.clear();
	// }
	ll n; cin>>n;
	cout<<fun(n,0)<<"\n";
	cerr<<"maxd "<<maxd<<"\n";
	// cerr<<SZ(dp)<<"\n";
	return 0;
}