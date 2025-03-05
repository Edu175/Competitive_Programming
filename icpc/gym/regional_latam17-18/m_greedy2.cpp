#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
const ll SEP=350;

void operator+=(vv &a, vv b){
	for(auto i:b)a.pb(i);
}

int main(){ET;
	ll n; cin>>n;
	vector<vector<vv>> a(n);
	fore(i,0,n){
		auto &v=a[i];
		vv tmp;
		ll m; cin>>m;
		fore(i,0,m){
			ll x; cin>>x;
			if(!SZ(tmp)||x<tmp[0])tmp.pb(x);
			else v.pb(tmp),tmp={x};
		}
		if(SZ(tmp))v.pb(tmp);
		// mergeo los a>=b con SEP
		auto u=v; v.clear();
		for(auto i:u){
			if(SZ(v)&&v.back()>=i)v.back().pop_back(),v.back()+=i;
			else v.pb(i);
			v.back().pb(SEP);
		}
		// for(auto &i:v)i.pb(SEP);
		cerr<<"u: ";
		for(auto i:u){
			cerr<<"{ ";
			for(auto j:i)cerr<<j<<" ";
			cerr<<"} ";
		};
		cerr<<"v: ";
		for(auto i:v){
			cerr<<"{ ";
			for(auto j:i)cerr<<j<<" ";
			cerr<<"} ";
		}cerr<<"\n";
	}
	
	vv p(n);
	typedef pair<vv,ll> node;
	priority_queue<node,vector<node>,greater<node>>pq;
	auto put=[&](ll i){
		pq.push({a[i][p[i]],i});
	};
	fore(i,0,n)put(i);
	
	vv ans;
	while(SZ(pq)){
		auto [v,i]=pq.top(); pq.pop();
		ans+=v;
		p[i]++;
		if(p[i]<SZ(a[i]))put(i);
	}
	for(auto i:ans)cerr<<i<<" ";;cerr<<"\n";
	reverse(ALL(ans));
	ll pot=1,res=0;
	fore(i,0,SZ(ans))if(ans[i]!=SEP){
		pot=mul(pot,365);
		res=add(res,mul(ans[i],pot));
	}
	cout<<res<<"\n";
}