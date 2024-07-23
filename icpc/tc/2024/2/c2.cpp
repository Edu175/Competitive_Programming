#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto dflg:v)cout<<dflg<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5e5+5,MAXV=(1ll<<20)+100;

struct edge{
	int y;
	list<edge>::iterator rev;
	edge(int y):y(y){}
};
list<edge> g[MAXV];
void add_edge(int a, int b){
	cout<<"added "<<a<<" "<<b<<"\n";
	g[a].push_front(edge(b)); auto ia=g[a].begin();
	if(a!=b)g[b].push_front(edge(a));
	auto ib=g[b].begin();
	ia->rev=ib; ib->rev=ia;
}
vector<int>p;
void go(int x){
	while(g[x].size()){
		int y=g[x].front().y;
		g[y].erase(g[x].front().rev);
		g[x].pop_front();
		go(y);
	}
	p.push_back(x);
}
vector<int> get_path(int x){
	p.clear(); go(x); reverse(ALL(p));
	return p;
}
ll flag=1;
ll vis[MAXV];
void dfs(ll x){
	vis[x]=1;
	ll ex=0;
	for(auto y:g[x]){
		if(!vis[y.y])dfs(y.y);
		ex+=y.y==x;
	}
	flag&=(SZ(g[x])+ex)%2==0;
}
ii a[MAXN];
ll n;
vector<int> camino(ll k){
	vector<ll>bor;
	ll mk=(1ll<<k)-1;
	fore(i,0,n){
		ll u=a[i].fst&mk,v=a[i].snd&mk;
		add_edge(u,v);
		bor.pb(v);
		bor.pb(u);
	}
	vector<int>r;
	dfs(bor[0]);
	for(auto i:bor)flag&=vis[i];
	if(flag)r=get_path(bor[0]);
	// cout<<" camino "<<k<<": "<<flag<<": "; imp(r);
	flag=1;
	for(auto i:bor)g[i].clear(),vis[i]=0;
	return r;
}
// ll value(vector<ii>a){
// 	ll k=20;
// 	cout<<SZ(a)<<" sz "<<endl;
// 	for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
// 	fore(i,0,n){
// 		k=min(k,(ll)__builtin_ctzll(a[i].snd^a[(i+1)%n].fst));
// 	}
// 	return k;
// }

// bool check(vector<ll>c, ll k){
// 	vector<ii>b;
// 	fore(i,0,SZ(c))if(i%2==0){
// 		ll idx=min(c[i],c[i+1])/2;
// 		ll sw=c[i]>c[i+1];
// 		if(sw)b.pb({a[idx].snd,a[idx].fst});
// 		else b.pb(a[idx]);
// 	}
// 	return value(b)==k;
// }

int main(){JET
	cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vector<int>res;
	ll r=0;
	for(ll k=20;k>=0;k--){
		res=camino(k);
		r=k;
		if(SZ(res)==2*n)break;
	}
	cout<<r<<"\n";
	map<ii,vector<ll>>mp;
	ll mk=(1ll<<r)-1;
	fore(i,0,n)mp[{a[i].fst&mk,a[i].snd&mk}].pb(i);
	// for(auto i:res)cout<<i<<" ";;cout<<" camino"<<endl;
	vector<ll>ans;
	fore(i,0,SZ(res)-1){
		auto x=res[i],y=res[i+1];
		if(SZ((mp[{x,y}]))){
			auto &dat=mp[{x,y}];
			ll idx=dat.back();
			dat.pop_back();
			ans.pb(2*idx),ans.pb(2*idx+1);
		}
		else {
			auto &dat=mp[{y,x}];
			assert(SZ(dat));
			ll idx=dat.back();
			dat.pop_back();
			ans.pb(2*idx+1),ans.pb(2*idx);
		}
	}
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	// assert(check(ans,r));
}