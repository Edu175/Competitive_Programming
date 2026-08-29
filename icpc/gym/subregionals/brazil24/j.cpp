#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=1005;
struct edge{
	ll x,y,c;	
};

vector<edge> eds;
vv ids_ed;
vector<ii> g[maxn];
vv G[maxn];
bool vis[maxn];

void dfs(ll u){
	vis[u]=1;
	for(auto [v,i]:g[u])if(!vis[v])dfs(v);
}
void fail(){
	cout<<"-1\n"; exit(0);
}


void dfsar(ll u, vv &ord){
	ord.pb(u); vis[u]=1;
	for(auto v:G[u]) if(!vis[v]) dfsar(v,ord);
}
vector<vv> cys;

bool ct(int x, edge &a){
	if(a.x == x || a.y == x) return true;
	return false;
}

ll dif(int x, edge &a){
	assert(ct(x,a));
	if(a.x == x) return a.y;
	return a.x;
}




ll jere[maxn];
bool check(int x, vv ar, ll m){
	ll col = -1;
	ar.pb(ar[0]);
	mset(jere,0);
	for(auto e:ar){
		// cout<<x+1<<" "<<e+1<<endl;
		// cout<<"la arista "<<e+1<<" dice "<<eds[e].x+1<<" "<<eds[e].y+1<<" "<<eds[e].c+1<<endl;
		if(eds[e].c == col) return false;
		if(!ct(x,eds[e])) return false;
		x = dif(x,eds[e]);
		col = eds[e].c;
		jere[e]=1;
	}
	// fore(i,0,m) if(!jere[i]) return false;
	return true;
}
void rot_well(vv &vs,ll wi, ll u, ll m){
	fore(t,0,SZ(vs))if(vs[t]==wi){
		rotate(vs.begin(),vs.begin()+t,vs.end());
		break;
	}
	if(!check(u,vs,m)){
		rotate(vs.begin(),vs.begin()+1,vs.end());
	}
}

void euler(ll n){
	ll m=SZ(eds);
	
	fore(i,0,m)if(!vis[i]){
		vv cy;
		dfsar(i,cy);
		
		fore(i,0,SZ(cy)) ids_ed[cy[i]]=SZ(cys);
		
		cys.pb(cy); 
		
	}
	fore(_,0,SZ(cys)-1){
		fore(u,0,n)if(SZ(g[u])){
			
			ll i=ids_ed[g[u][0].snd],wi=g[u][0].snd;
			
			ll j=-1,wj=-1;
			for(auto [v,t]: g[u])if(ids_ed[t]!=i){
				j=ids_ed[t];wj=t; break; 
			}			
			if(j<0) continue;
			vv cy=cys[i];
			rot_well(cy,wi,u,m);
			
			rot_well(cys[j],wj,u,m);
			
			if(eds[cy.back()].c==eds[cys[j][0]].c) reverse(ALL(cy));
			
			if(eds[cy[0]].c==eds[cys[j].back()].c) reverse(ALL(cy));
			// cout<<"voy a unir desde el nodo "<<u<<"\n";
			// show(cy);
			// show(cys[j]);
			// cout<<"\n";
			for(auto ed:cys[j]) cy.pb(ed);
			for(auto ed: cy) ids_ed[ed]=SZ(cys);
			cys.pb(cy);
			break;
		}
	}
}




vv cn[maxn];
int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	ids_ed.resize(m);
	fore(i,0,m){
		ll x,y,c; cin>>x>>y>>c; x--,y--,c--;
		g[x].pb({y,SZ(eds)});
		g[y].pb({x,SZ(eds)});
		eds.pb({x,y,c});
	}
	fore(i,0,n) if(SZ(g[i])) {dfs(i); break;}
	fore(i,0,n)if((SZ(g[i])&1)||(SZ(g[i])&&!vis[i]))fail();
		
	
	fore(u,0,n){
		fore(i,0,k) cn[i].clear();
		fore(i,0,SZ(g[u])) cn[eds[g[u][i].snd].c].pb(i);
		fore(i,0,k) if(SZ(cn[i])>SZ(g[u])/2) fail();
		priority_queue<ii> pq;
		fore(i,0,k)if(SZ(cn[i])) pq.push({SZ(cn[i]),i});
		while(SZ(pq)){
			auto [sz1,i]=pq.top(); pq.pop();
			auto [sz2,j]=pq.top(); pq.pop();
			sz1--;sz2--;
			ll ar1=g[u][cn[i][sz1]].snd,ar2=g[u][cn[j][sz2]].snd;
			G[ar1].pb(ar2);
			G[ar2].pb(ar1);
			if(sz1) pq.push({sz1,i});
			if(sz2) pq.push({sz2,j});
		} 
	}
	
	mset(vis,0);
	euler(n);
	ll in=eds[cys.back()[0]].x;
	if(!check(in,cys.back(),m)) in=eds[cys.back()[0]].y;
	assert(check(in,cys.back(),m));
	cout<<in+1<<"\n";
	for(auto ed: cys.back()){
		cout<<ed+1<<" ";
	}
	cout<<"\n";
	return 0;
}