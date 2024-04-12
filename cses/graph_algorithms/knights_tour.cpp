#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll MAXN=70;

vector<ll> g[MAXN];

ll cnt=0,vis[MAXN],deg[MAXN];
void answer(){
	fore(i,0,8){
		fore(j,0,8)cout<<vis[8*i+j]<<" ";
		cout<<"\n";
	}
	exit(0);
}
void dfs(ll x){
	vis[x]=++cnt;
	if(cnt==64)answer();
	for(auto y:g[x])deg[y]--;
	vector<ll>u,v;
	for(auto y:g[x])if(!vis[y]){
		if(deg[y]<=1)u.pb(y);
		else v.pb(y);
	}
	if(SZ(u)>1&&!(SZ(u)==2&&deg[u[0]]==1&&deg[u[1]]==1))goto end;
	//if(SZ(u)>3||(SZ(u)==2&&deg[u[0]]+deg[u[1]]==0))goto end;
	for(auto y:u)dfs(y);
	for(auto y:v)dfs(y);
	end:
	for(auto y:g[x])deg[y]++;
	vis[x]=0;
	--cnt;
}

int main(){FIN;
	fore(i,0,8)fore(j,0,8){
		fore(h,-2,3)fore(v,-2,3)if(h&&v){
			set<ll>st;
			st.insert(abs(v));
			st.insert(abs(h));
			if(SZ(st)<2)continue;
			ll i1=i+h,j1=j+v;
			if(i1<0||i1>=8||j1<0||j1>=8)continue;
			g[8*i+j].pb(8*i1+j1);
		}
	}
	ii s; cin>>s.fst>>s.snd; s.fst--,s.snd--; swap(s.fst,s.snd);
	fore(x,0,64)deg[x]=SZ(g[x]);
	dfs(s.fst*8+s.snd);
	assert(0);
	return 0;
}
