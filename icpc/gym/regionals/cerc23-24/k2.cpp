#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
vector<int> G[MAXN]; int n;
struct edge{int u,v,comp;bool bridge;};
vector<edge> e;
void add_edge(int u, int v){
    G[u].pb(SZ(e));G[v].pb(SZ(e));
    e.pb((edge){u,v,-1,false});
}
 
int D[MAXN],B[MAXN],T;
int nbc;
int art[MAXN];
stack<int> st;
void dfs_(int u, int pe){
    B[u]=D[u]=T++;
    for(int ne:G[u])if(ne!=pe){
        int v=e[ne].u^e[ne].v^u;
        if(D[v]<0){
            st.push(ne);dfs_(v,ne);
            if(B[v]>D[u])e[ne].bridge = true;
            if(B[v]>=D[u]){
                art[u]++;
                int last;
                do{
                    last = st.top();
                    st.pop();
                    e[last].comp = nbc;
                } while(last!=ne);
                nbc++;
            }
            B[u]=min(B[u],B[v]);
        }
        else if(D[v]<D[u])st.push(ne),B[u]=min(B[u],D[v]);
    }
}
 
void doit(){
    mset(D,-1);mset(art,0);
    nbc=T=0;
    fore(i,0,n)if(D[i]<0)dfs_(i,-1),art[i]--;
}
vector<ii> g[MAXN];

ll ban=0,done=0;
vv path;
ll vis[MAXN];
void dfs(ll x){
	done|=x==1;
	if(done)return;
	vis[x]=1;
	for(auto [y,i]:g[x])if(!done&&ban!=i&&!vis[y]){
		path.pb(i);
		dfs(y);
		if(done)return;
		path.pop_back();
	}
}
vv cyc;
vector<ii>ed;
ll go(ll x, ll i, ll pr=0){
	ll ret=ed[i].fst;
	if(ret==x)ret=ed[i].snd;
	if(pr)cout<<"MOVE "<<ret<<"\n";
	return ret;
}
ll esta[MAXN];
vv p;

void dfs2(ll x){
	done|=esta[x];
	if(done)return;
	vis[x]=1;
	for(auto [y,i]:g[x])if(!done&&!vis[y]){
		p.pb(i);
		dfs2(y);
		if(done)return;
		p.pop_back();
	}
}

int main(){JET
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		g[u].pb({v,i});
		g[v].pb({u,i});
		add_edge(u,v);
		ed.pb({u,v});
	}
	doit();
	ll k=magia(); // index de arista
	ban=k;
	ll y=go(1,k);
	dfs(y);
	cyc=path;
	cyc.pb(k);
	for(auto i:cyc)esta[ed[i].fst]=esta[ed[i].snd]=1;
	mset(vis,0);
	done=0;
	dfs2(0);
	ll x=0;
	for(auto i:p){
		x=go(x,i,1);
	}
	cout<<"DROP ";
	for(auto i:p)cout<<i<<" ";;cout<<"\n";
	ll idx=0;
	fore(i,0,SZ(cyc))if(ed[cyc[i]])
    return 0;
}