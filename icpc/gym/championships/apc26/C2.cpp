#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x)  for(auto [a,i]:x){cout<<a<<" ";}cout<<"\n";
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;

queue<int> q;
const int MAXN = 1e5+10, MAXM = 2e5+100;
ll res[MAXM], F[MAXN];
set<ii> g[MAXN];
set<ii> ori[MAXN];
int INF = 1e7+100;

void borrar(int x){
	for(auto [y,i] : ori[x]) g[y].erase({x,i});
}

bool tiene(int x, int y){
	auto it = g[x].lower_bound({y,-1});
	// cout<<(*it).fst<<" "<<(*it).snd<<"\n";
	if(it == g[x].end() || (*it).fst != y) return false;
	res[(*it).snd] = INF--;
	return true;
}

bool dfs(int x){
	// cout<<x+1<<endl;
	if(!SZ(q))return true;
	borrar(x);
	ll aux = q.front();
	if(tiene(x,aux)){
		q.pop();
		F[aux] = x;
		return dfs(aux);
	}
	if(!SZ(g[x])){
		assert(F[x]>=0);
		return dfs(F[x]); 
	}
	// show(g[x]);
	return false;
}

int main(){
	JET
	mset(F,-1); 
	fore(i,0,MAXM) res[i] = 1;
	ll n, m; cin>>n>>m;
	fore(i,0,m){
		ll x,y; cin>>x>>y; x--,y--;
		ori[x].insert({y,i});
		ori[y].insert({x,i});
	}
	fore(i,0,n) g[i] = ori[i];
	fore(i,0,n){
		ll x; cin>>x;x--;
		q.push(x);
	}
	ll first = q.front();
	q.pop();
	if(!dfs(first)) cout<<"impossible";
	else fore(i,0,m) cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}