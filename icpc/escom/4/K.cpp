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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;
ll n;
map<vv,ld> dp;
ld f(vv a){
	// if(!SZ(a))return -INF;
	if(SZ(a)<=1)return 0;
	if(dp.count(a))return dp[a];
	ll ac_and=a[0],ac_or=a[0];
	for(auto i:a){
		ac_and&=i;
		ac_or|=i;
	}
	ld res=INF;
	fore(j,0,n)if(!(ac_and>>j&1)&&(ac_or>>j&1)){
		vector<vv> c(2);
		for(auto mk:a)c[mk>>j&1].pb(mk);
		ld L=f(c[0])*SZ(c[0]);
		ld R=f(c[1])*SZ(c[1]);
		ld cur=(L+R)/SZ(a)+1;
		res=min(res,cur);
	}
	return dp[a]=res;
	// return res;
}

const ld EPS=1e-10;
int main(){
    JET
	ll m; cin>>n>>m;
	vector<ll> a(m);
	fore(i,0,m){
		ll k; cin>>k;
		fore(_,0,k){
			ll v; cin>>v;
			a[i]|=1ll<<v;
		}
	}
	sort(ALL(a));
	// ll sz=SZ(a);
	// a.resize(unique(ALL(a))-a.begin());
	ld res=f(a);
	if(res>n){
		cout<<"not possible\n";
		return 0;
	}
	assert(res<=n);
	cout<<fixed<<setprecision(15)<<res<<"\n";
    return 0;
}
