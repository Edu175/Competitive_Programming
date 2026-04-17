#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first 
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

map<ll,ll> uf,res,vis;

bool l_divide_r(ll l, ll r){
	return !(r%l);
}
vv div(ll x){
	vv r;
	for(ll i=1; i*i<=x; i++){
		if(l_divide_r(i,x)){
			r.pb(i);
			if(x/i!=i) r.pb(x/i);
		}
	}
	return r;
}
vv di;
ll a,b;

const ll maxn=10000000000000000LL;
void dfs(ll x){
	assert(!vis[x]);
	
	vis[x]=1;
	
	res[uf[x]]^=x;
	
	for(auto &d: di){
		if(d>x) return;
		if(l_divide_r(d,x)){
			
			
			ll l=a*d+b;
			
			if(l_divide_r(x,l)){
				
				ll y=(l/x)*d;
				
				if(y<=maxn&&!vis[y]&&gcd(x,y)==d){
					// cout<<x<<" --"<<d<<"-->"<<y<<" voy \n";
					// assert(lcm(x,y)==l);
					// assert(lcm(x,y)==a*gcd(x,y)+b);
					uf[y]=uf[x];
					dfs(y);
				
				}
			}
		}
	}
}
int main(){
	JET
	cin>>a>>b;
	di=div(b);
	sort(ALL(di));
	ll q; cin>>q;
	while(q--){
		
		ll x; cin>>x;
		
		if(!vis[x]) res[x]=0,uf[x]=x,dfs(x);
		
		cout<<res[uf[x]]<<"\n";
	
	}
	return 0;
}