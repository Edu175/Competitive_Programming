#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
vector<ll> g[MAXN];

int main(){
	JET
	ll n,m; cin>>n>>m;
	set<ll>st,lib;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll res=0;
	fore(i,1,n){
		lib.insert(i);
	}
	for(auto i:g[0])st.insert(i);
	while(SZ(lib)){
		ll v=-1;
		for(auto i:lib){
			if(!st.count(i)){
				v=i;
				break;
			}
		}
		if(v==-1)v=*lib.begin(),res++;
		set<ll>sti;
		for(auto i:g[v]){
			if(st.count(i))sti.insert(i);
		}
		st=sti;
		lib.erase(v);
	}
	cout<<res<<"\n";
	return 0;
}