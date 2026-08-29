#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vv g[MAXN];
ll dfs(ll x){
	vv a;
	for(auto y:g[x])a.pb(dfs(y));
	if(!SZ(a))return 1;
	sort(ALL(a));
	a.back()--;
	return 1+*max_element(ALL(a));
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n){
			ll p; cin>>p; p--;
			if(p!=-1)g[p].pb(i);
		}
		cout<<dfs(0)<<"\n";
	}
	return 0;
}