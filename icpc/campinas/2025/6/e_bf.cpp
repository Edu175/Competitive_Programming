#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


const ll MAXN=5e3+5;
vv g[MAXN];
vector<ii> dir={{1,0},{0,1},{-1,0},{0,-1}};
bitset <MAXN> vis;
set<pair<pair<bitset <MAXN>,ll>,bool>>  S;
bool dfs(ll i, bool b){
	vis[i]=true;
	pair<pair<bitset <MAXN>,ll>,bool> x= (pair<pair<bitset <MAXN>,ll>,bool>){(pair<bitset <MAXN>,ll>){vis,i},0};
	auto it=S.lower_bound(x);
	if((it!=S.end())&&((*it).fst=(pair<bitset <MAXN>,ll>){vis,i}))
	if(b){
		bool ans=false;
		for(ll j:g[i])if(!vis[j]){
			ans=ans|dfs(j,0);
		}
		vis[i]=false;
		return ans;
	}
	bool ans=true;
	for(ll j:g[i])if(!vis[j]){
		ans=ans&dfs(j,1);
	}
	vis[i]=false;
	return ans;
}
int main(){
	JET
	ll n; cin>>n;
	set<pair<ii,ll>> s;
	map<ll,ii> m;
	mset(vis,0);
	fore(i,0,n){
		ll x,y;
		cin>>x>>y;
		for(auto [ab,lr]: dir){
			auto it=s.lower_bound((pair<ii,ll>){(ii){x+ab,y+lr},-1});
			if(it!=s.end()&&(*it).fst==ii({x+ab,y+lr})){
				ll j=(*it).snd;
				g[i].pb(j);
				g[j].pb(i);
			}
		}
		s.insert((pair<ii,ll>){(ii){x,y},i});
		m[i]=(ii){x,y};
	}
	vector<ii> ans;
	fore(i,0,n){
		if(dfs(i,0)) ans.pb(m[i]);
	}
	sort(ALL(ans));
	cout<<SZ(ans)<<"\n";
	fore(i,0,SZ(ans)) cout<<ans[i].fst<<" "<<ans[i].snd<<"\n";
	return 0;
}