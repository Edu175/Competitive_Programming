#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 505;
char g[MAXN][MAXN];
ll vis[MAXN][MAXN];

map<char,ii> mp ={{'>',{0,1}},{'<',{0,-1}},{'^',{-1,0}},{'v',{1,0}}};
vector<ii> dir = {{0,1},{0,-1},{1,0},{-1,0}};

ii ini = {-1,-1};
map<ii,ll> cyc;
map<ii,ll> ciclos [MAXN*MAXN];


bool piso(int i, int j){return g[i][j] == '.' || g[i][j] == '#';}

void search_cycles(int i, int j){
	if(vis[i][j] == 2) {ini = {i,j};return;}
	vis[i][j] = 2;
	ii d = mp[g[i][j]];
	ll x = i+d.fst, y = j+d.snd;
	if(g[x][y] != '#' && g[x][y] != '.' && vis[x][y] != 1)search_cycles(x,y);
	vis[i][j] = 1;
}

ll c = 0;
void do_cycle(int i, int j, bool pase){
	if(i == -1) return;
	// cout<<"cycle at "<<i<<" "<<j<<" : "<<g[i][j]<<"\n";
	if(ini == (ii){i,j}  && pase){
		vis[i][j] = 1;
		c++;
		return;
	}
	cyc[{i,j}] = c;
	for(auto d:dir)if(g[i+d.fst][j+d.snd] =='#') ciclos[c][{i+d.fst,j+d.snd}]++;
	do_cycle(i+mp[g[i][j]].fst,j+mp[g[i][j]].snd,1);
}

map<ii,vector<ii>> grafo;
set<ii> root;


map<ii,ll> h;
ll res = 0;
ll acc = 0;
void solve(int i, int j){
	if(i == -1){
		h = ciclos[j];
		acc = SZ(ciclos[j]);
	}
	else{
		for(auto d:dir)if(g[i+d.fst][j+d.snd] == '#'){
			if(!h[{i+d.fst,j+d.snd}]++) acc++;
		}
	}
	for(auto hijo : grafo[{i,j}]) solve(hijo.fst,hijo.snd);
	res = max(res,acc);
	// cout<<"en la pos "<<i<<" "<<j<<" tengo para agarrar "<<acc<<"\n";
	if(i!=-1){
		for(auto d:dir)if(g[i+d.fst][j+d.snd] == '#'){
			h[{i+d.fst,j+d.snd}]--;
			if(!h[{i+d.fst,j+d.snd}]) acc--;
		}
	}
}

int main(){
	JET
	fore(i,0,MAXN)fore(j,0,MAXN)g[i][j] = '.';
	ll n,m; cin>>n>>m;
	fore(i,1,n+1)fore(j,1,m+1)cin>>g[i][j];
	
	fore(i,0,MAXN)fore(j,0,MAXN){
		if(piso(i,j) || vis[i][j]) continue;
		ini = {-1,-1};
		search_cycles(i,j);
		// cout<<"start cycle\n";
		do_cycle(ini.fst,ini.snd,0);
		// cout<<"end cycle\n";		
	}
	mset(vis,0);
	fore(i,0,MAXN)fore(j,0,MAXN){
		if(piso(i,j) || cyc.count({i,j})) continue;
		ll x = i+mp[g[i][j]].fst, y = j+mp[g[i][j]].snd;
		if(piso(x,y))root.insert({i,j});
		else if(cyc.count({x,y}))grafo[{-1,cyc[{x,y}]}].pb({i,j});
		else grafo[{x,y}].pb({i,j});
	}
	fore(i,0,c) root.insert({-1,i});
	
	for(auto [i,j] : root){
		h.clear(); acc = 0;
		solve(i,j);
	}
	cout<<res<<"\n";
	return 0;
}

