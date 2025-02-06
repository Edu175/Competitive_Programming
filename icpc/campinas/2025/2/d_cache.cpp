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
void dfs(ll x, ll fa, vector<bool> &mk){
	vis[x]=1; sz++;
	for(auto y:g[x])if((mk[y])&&y!=fa){
		if(vis[y])cyc=1;
		else dfs(y,x,mk);
	}
}

ll greedy(vector<bool> &mk){
	fore(i,0,n)vis[i]=0;
	
	ll res=0;
	fore(i,0,n)if(mk[i]&&!vis[i]){
		sz=0,cyc=0;
		dfs(i,-1,mk);
		res+=(sz+cyc)/2;
	}
	// cout<<"greedy "<<cv(mk)<<": "<<res<<"\n";
	return res;
}
int f(vector<bool> mk, ll mvc){
	if(mvc>k)return 0;
	if(mvc==n)return 0;
	ll mx=-1,wh=-1;
	fore(x,0,n)if(mk[x]){
		ll deg=0;
		for(auto y:g[x])deg+=mk[y];
		if(deg>mx)mx=deg,wh=x;
	}
	if(mx<=2){
		ll cur=greedy(mk);
		return cur;
	}
	mk[wh]=0;
	ll res=1+f(mk,mvc+1);
	// mk[wh]=1;
	for(auto y:g[wh])if(mk[y])mk[y]=0;
	res=min(res,mx+f(mk,mvc+mx));
	return res;
}
ll ccnt=0,nl[MAXN],ori[MAXN];
void chdfs(ll x){
	nl[x]=ccnt; ori[ccnt++]=x;
	for(auto y:g[x])if(nl[y]==-1)chdfs(y);
}
void cache(){
	ccnt=0;
	fore(i,0,n)nl[i]=-1;
	fore(i,0,n)if(nl[i]==-1)chdfs(i);
	vector<ii>ed;
	fore(x,0,n)for(auto y:g[x])ed.pb({nl[x],nl[y]});
	fore(i,0,n)g[i].clear();
	for(auto [x,y]:ed)g[x].pb(y);
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		// cerr<<"testcase"<<endl;
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
		// cache();
		ll res=k+5; vv best;
		vector<bool> all(n,1);
		fore(x,0,n){
			all[x]=0;
			ll resi=1+f(all,1);
			all[x]=1;
			if(resi<res)res=resi,best.clear();
			if(resi==res)best.pb(x);
			// cout<<x<<": "<<resi<<"\n";
		}
		if(res>k)cout<<"-1\n";
		else {
			cout<<res<<" "<<SZ(best)<<"\n";
			// for(auto &i:best)i=ori[i];
			// sort(ALL(best));
			for(auto i:best)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}