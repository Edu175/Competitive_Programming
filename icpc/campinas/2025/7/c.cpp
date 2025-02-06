#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

struct node{
	ll mex=0;
	set<ll>st;
	node(){}
	void add(ll x){
		st.insert(x);
		while(st.count(mex))mex++;
	}
	
};

vv g[MAXN];
ll a[MAXN],res[MAXN];
node dfs(ll x){
	node ans;
	ans.add(a[x]);
	for(auto y:g[x]){
		auto cur=dfs(y);
		if(SZ(ans.st)<SZ(cur.st))swap(ans,cur);
		for(auto i:cur.st)ans.add(i);
	}
	res[x]=ans.mex;
	return ans;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		ll p; cin>>p; p--;
		if(p!=-1)g[p].pb(i);
	}
	fore(i,0,n)cin>>a[i],a[i]--;
	dfs(0);
	fore(i,0,n)cout<<res[i]+1<<" ";;cout<<"\n";
	return 0;
}