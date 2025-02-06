#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1005;
vv g[MAXN];
ll n,k;
ll vis[MAXN],sz=0,cyc=0;
string cv(vector<bool> b){
	string s;
	for(auto i:b)s.pb('0'+i);
	return s;
}
vv p;
void dfs(ll x, ll fa, vector<bool> &mk){
	vis[x]=1; sz++;
	p.pb(x);
	ll did=0;
	for(auto y:g[x])if(mk[y]&&y!=fa){
		if(vis[y])cyc=1;
		else {
			if(did)reverse(ALL(p));
			did=1;
			dfs(y,x,mk);
		}
	}
}

ll ans[MAXN];
ll greedy(vector<bool> &mk, ll mvc){
	fore(i,0,n)vis[i]=0;
	
	ll res=mvc;
	vector<vv>ps;
	vv is;
	fore(i,0,n)if(mk[i]&&!vis[i]){
		sz=0,cyc=0; p.clear();
		dfs(i,-1,mk);
		res+=(sz+cyc)/2;
		ps.pb(p),is.pb(cyc);
	}
	fore(i,0,SZ(ps)){
		auto p=ps[i]; auto cyc=is[i];
		fore(j,0,SZ(p)){
			if(j%2||cyc||SZ(p)%2==0)ans[p[j]]=min(ans[p[j]],res);
		}
	}
	// cout<<"greedy "<<cv(mk)<<" "<<mvc<<": "<<res<<"\n";
	return res;
}


int f(vector<bool> mk, ll mvc){
	// cout<<"f "<<cv(mk)<<" "<<mvc<<"\n";
	auto _mk=mk;
	if(mvc>k)return mvc;
	if(mvc==n)return mvc;
	ll mx=-1,wh=-1;
	fore(x,0,n)if(mk[x]){
		ll deg=0;
		for(auto y:g[x])deg+=mk[y];
		if(deg>mx)mx=deg,wh=x;
	}
	if(mx<=2)return greedy(mk,mvc);
	mk[wh]=0;
	ll go0=f(mk,mvc+1);
	ans[wh]=min(ans[wh],go0);
	mk[wh]=1; // could be dropped
	vv nod;
	for(auto y:g[wh])if(mk[y])mk[y]=0,nod.pb(y);
	ll go1=f(mk,mvc+mx);
	for(auto i:nod)ans[i]=min(ans[i],go1);
	// cout<<"f "<<cv(_mk)<<" "<<mvc<<": "<<wh<<": "<<go0<<" "<<go1<<"\n";;
	return min(go0,go1);
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m>>k;
		fore(i,0,n){
			g[i].clear();
		}
		set<ii>st;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			if(u>v)swap(u,v);
			if(st.count({u,v}))continue;
			st.insert({u,v});
			g[u].pb(v);
			g[v].pb(u);
		}
		ll res=k+5; vv best;
		fore(i,0,n)ans[i]=k+5;
		f(vector<bool>(n,1),0);
		fore(x,0,n){
			ll resi=ans[x];
			if(resi<res)res=resi,best.clear();
			if(resi==res)best.pb(x);
			// cout<<x<<": "<<resi<<"\n";
		}
		if(res>k)cout<<"-1\n";
		else {
			cout<<res<<" "<<SZ(best)<<"\n";
			for(auto i:best)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}