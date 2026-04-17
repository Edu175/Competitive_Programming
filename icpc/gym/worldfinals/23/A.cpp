#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll tra(char c){
	string s="RGB";
	fore(i,0,3)if(s[i]==c)return i;
	assert(0);
}
const ll MAXN=4e5+5;
void fail(){
	cout<<"impossible\n";
	exit(0);
}
ll opu(ll a, ll s){
	ll r=(3+s-a)%3;
	return r;
}
vector<ii> g[MAXN];
ll bad=0,sum=0;
ll col[MAXN];
ll vis[MAXN];
vv nod;
void dfs(ll x){
	sum+=col[x];
	nod.pb(x);
	vis[x]=1;
	for(auto [y,w]:g[x]){
		ll qu=opu(col[x],w);
		if(col[y]==-1){
			col[y]=qu;
			dfs(y);
		}
		else {
			bad|=col[y]!=qu;
		}
	}
}

ii doit(ll x, ll t){
	col[x]=t; bad=0; sum=0;
	dfs(x);
	for(auto i:nod)col[i]=-1;
	nod.clear();
	return {bad,sum};
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<set<ll>> has(n);
	vector<vv> to(m);
	vv a(n);
	fore(i,0,n){
		char c; cin>>c;
		a[i]=tra(c);
	}
	fore(i,0,m){
		ll k; cin>>k;
		fore(_,0,k){
			ll x; cin>>x; x--;
			has[x].insert(i);
			to[i].pb(x);
		}
	}
	ll res=0;
	queue<ll> q;
	vv did(m);
	fore(i,0,n)if(SZ(has[i])==1)q.push(i);
	while(SZ(q)){
		auto i=q.front(); q.pop();
		if(!SZ(has[i]))continue;
		ll j=*has[i].begin();
		did[j]=1;
		ll c=(3-a[i])%3;
		res+=c;
		for(auto i:to[j]){
			a[i]=(a[i]+c)%3;
			has[i].erase(j);
			if(SZ(has[i])==1)q.push(i);
		}
	}
	fore(i,0,n){
		vv v;
		for(auto j:has[i])v.pb(j);
		assert(SZ(v)!=1);
		if(SZ(v)==0){
			if(a[i])fail();
			continue;
		}
		ll c=(3-a[i])%3;
		ll x=v[0],y=v[1];
		g[x].pb({y,c});
		g[y].pb({x,c});
	}
	mset(col,-1);
	fore(x,0,m)if(!vis[x]){
		ii cur={1,1e10};
		fore(t,0,3)cur=min(cur,doit(x,t));
		if(cur.fst)fail();
		res+=cur.snd;
	}
	cout<<res<<"\n";
	return 0;
}