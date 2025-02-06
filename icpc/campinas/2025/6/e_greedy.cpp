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
ll sz=0,out[MAXN];
void dfs(ll x){
	out[x]=1; sz++;
	for(auto y:g[x])if(!out[y])dfs(y);
}
ll n;
bool solve(ll rt){
	queue<ll>q;
	fore(i,0,n)out[i]=0;
	sz=0;
	vv win(n);
	vv deg(n);
	fore(x,0,n)deg[x]=SZ(g[x]);
	fore(i,0,n)if(i!=rt&&deg[i]==1)q.push(i);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		if(out[x])continue;
		out[x]=1;
		for(auto y:g[x])if(!out[y]){
			deg[y]--;
			if(!win[x])win[y]=1;
			if(deg[y]<=1||!win[x])q.push(y);
		}
	}
	if(out[rt])return win[rt];
	dfs(rt);
	return sz%2==0;
}

int main(){
	JET
	cin>>n;
	map<ii,ll>mp;
	vector<ii>ps,ans;
	fore(i,0,n){
		ll x,y; cin>>x>>y; ps.pb({x,y});
		assert(!mp.count({x,y}));
		mp[{x,y}]=i;
		for(auto [a,b]:dir){
			a+=x,b+=y;
			if(mp.count({a,b})){
				ll j=mp[{a,b}];
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	fore(i,0,n){
		if(!solve(i))ans.pb(ps[i]);
	}
	sort(ALL(ans));
	cout<<SZ(ans)<<"\n";
	for(auto i:ans)cout<<i.fst<<" "<<i.snd<<"\n";
	return 0;
}