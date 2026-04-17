#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ll> g[MAXN];
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

ll a[MAXN],b[MAXN],p[MAXN],w[MAXN];
ll n,k,res=0;
vector<ordered_set>h;
ll merge(ll x, ll y){
	if(x==-1)return y;
	if(y==-1)return x;
	if(SZ(h[y])>SZ(h[x]))swap(x,y);
	for(auto i:h[y])h[x].insert(i);
	h[y].clear();
	return x;
}
void dfs(ll x){
	for(auto y:g[x]){
		dfs(y);
		w[x]=merge(w[x],w[y]);
	}
	//cout<<x<<": "<<w[x]<<"\n";
	h[w[x]].insert({a[x]*k,x});
	ll q=h[w[x]].order_of_key({a[x],-1}),all=lower_bound(b,b+n,a[x])-b;
	res+=(all-q)*q;
	/*cout<<x<<": "<<w[x]<<": { ";
	for(auto i:h[w[x]])cout<<i.fst<<","<<i.snd<<" ";
	cout<<"} : "<<all<<" "<<q<<"\n";*/
}
int main(){FIN;
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		//cout<<"\n";
		cin>>n>>k;
		fore(i,0,n){
			g[i].clear();
			w[i]=-1;
		}
		h.clear();
		res=0;
		fore(i,0,n)cin>>a[i],b[i]=a[i]*k;
		sort(b,b+n);
		fore(i,0,n-1){
			ll v; cin>>v; v--;
			g[v].pb(i+1),p[i+1]=v;
		}
		fore(i,0,n)if(!SZ(g[i])){
			ordered_set ad;
			ad.insert({a[i]*k,i});
			h.pb(ad),w[i]=SZ(h)-1;
			//cout<<i<<" --> "<<w[i]<<": ";
			//imp(h[w[i]]);
		}
		dfs(0);
		cout<<res<<"\n";
	}
	return 0;
}
// NO FAREWELL: KEEP GOOGLE COMPETITIONS ALIVE
