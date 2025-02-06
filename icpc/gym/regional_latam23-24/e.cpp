#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5;

struct Cmp{
	bool operator()(const ii &a, const ii &b)const{
		return a.fst*b.snd>b.fst*a.snd;
	}
};
Cmp cmp; // for direct usage call cmp(a,b)
vv g[MAXN];
ll fij=0;
ii merge(ii a, ii b){ // {sum,cant}
	fij+=a.snd*b.fst; // !!! dont make unnecesary merges (i.e. for debugging)
	a.fst+=b.fst;
	a.snd+=b.snd;
	return a;
}
ll s;
typedef priority_queue<ii,vector<ii>,Cmp> node;
node dfs(ll x, ll fa){
	node ans;
	for(auto y:g[x])if(y!=fa){
		auto cur=dfs(y,x);
		if(SZ(ans)<SZ(cur))swap(ans,cur);
		while(SZ(cur))ans.push(cur.top()),cur.pop();
	}
	ii a={x+1,1};
	while(SZ(ans)&&(x==s||cmp(a,ans.top())))
		a=merge(a,ans.top()),ans.pop();
	ans.push(a);
	return ans;
}

int main(){
	ET;
	ll n; cin>>n>>s; s--;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto ans=dfs(s,-1);
	fij+=ans.top().fst;
	cout<<fij<<"\n";
}