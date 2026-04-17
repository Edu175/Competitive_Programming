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

ll A,B;

set<ll> vis;
ll res;

vv divs;

ll maxn = 1000 * 1000 * 1000;


void get_divs(ll x){
	for(ll i = 1;i*i<=x;i++){
		if(x%i == 0){
			divs.pb(i);
			if(i*i!=x) divs.pb(x/i);
		}
	}	
}

void dfs(ll x){
	vis.insert(x);
	res ^= x;
	for(auto d:divs){
		if(x%d != 0) continue;
		ll l = A*d+B;
		if(l%x != 0) continue;
		ll y = (l/x) * d;
		if(y>maxn || y<=0 || gcd(y,x)!=d) continue;
		
	}
}

int main(){
	JET
	cin>>A>>B;
	get_divs(B);
	ll n; cin>>n;
	while(n--){
		vis.clear(); res = 0;
		ll x; cin>>x;
		dfs(x);
	}
	
	
	return 0;
}