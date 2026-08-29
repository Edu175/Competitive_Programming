#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
// typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)
ll fpow(ll b, ll e){
	ll res=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)res=mul(res,b);
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}

vector<vv> all;
ll n;
vv a;

void rec(ll sum){
	if(sum==n)all.pb(a);
	fore(v,SZ(a)?a.back():1,n-sum+1){
		a.pb(v);
		rec(sum+v);
		a.pop_back();
	}
}
// ull hsh(vv a){
// 	ull ret=0;
// 	for(auto i:a)ret=ret*3213351ull+ull(i);
// 	return ret;
// }
// vector<ull> all_hs;
ll id(vv a){
	// ull h=hsh(a);
	ll ret=lower_bound(ALL(all),a)-all.begin();
	assert(ret<SZ(all)&&all[ret]==a);
	return ret;
}
int main(){
    JET
	ll k,t; cin>>n>>k>>t;
	rec(0);
	// for(auto i:all)all_hs.pb(hsh(i));
	sort(ALL(all));
	// cerr<<"cant "<<SZ(all)<<"\n"; // 5604 is the partition number of 30
	// return 0;
	ll sz=SZ(all);
	vector<vector<ii>> g(sz);
	// ll cantidad=0;
	for(auto a:all){
		vv to(sz);
		fore(i,0,SZ(a)){
			fore(c,1,a[i]){
				auto b=a; b[i]=c; b.pb(a[i]-c);
				sort(ALL(b));
				auto &wh=to[id(b)];
				addig(wh,a[i]);
			}
			fore(j,i+1,SZ(a)){
				auto b=a; b.erase(b.begin()+j);
				b[i]=a[i]+a[j];
				ll coef=mul(2,mul(a[i],a[j]));
				sort(ALL(b));
				auto &wh=to[id(b)];
				addig(wh,coef);
			}
		}
		ll i=id(a);
		fore(j,0,sz)if(to[j]){
			ll coef=to[j];
			coef=mul(coef,(MOD+1)/2);
			g[i].pb({j,coef});
			// cantidad++;
		}
	}
	// cerr<<"cantidad "<<cantidad<<"\n"; // 96594 when n=30
	vv dp(sz); dp[id(vv(n,1))]=1;
	fore(_,0,k){
		vv ant(sz);
		swap(ant,dp);
		fore(i,0,sz){
			auto &res=dp[i];
			for(auto [j,coef]:g[i])addig(res,mul(coef,ant[j]));
		}
		// cout<<"vuelta "<<_<<"\n";
		// for(auto [a,b]:dp)cout<<a<<": "<<b<<"\n";
	}
	// return 0;
	while(t--){
		vv a(n); fore(i,0,n)cin>>a[i],a[i]--;
		vv zs;
		vv vis(n);
		fore(x,0,n)if(!vis[x]){
			ll z=0;
			for(ll y=x;!vis[y];y=a[y])vis[y]=1,z++;
			zs.pb(z);
		}
		sort(ALL(zs));
		ll res=dp[id(zs)];
		// cerr<<"query "<<a<<": "<<zs<<": ";
		cout<<res<<"\n";
	}
    return 0;
}
