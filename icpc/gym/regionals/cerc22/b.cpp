#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 3e3;
ll ban[MAXN];
vv g[MAXN];

void aristas(int x,int n){
	g[x].clear();
	if(ban[x])return;
	fore(i,0,n){
		ll flipx = x^(1<<i);
		if(ban[flipx]) continue;
		// cout<<"arista de "<<x<<" a "<<flipx<<"\n";
		g[x].pb(flipx);
	}
}

int nn;
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(){
	queue<int> q; mset(ds,-1); bool r = false;
	fore(i,0,nn) if(mt2[i] < 0)ds[i] = 0, q.push(i);
	while(SZ(q)){
		int x = q.front();q.pop();
		for(int y : g[x]){
			if(mt[y] >= 0 &&ds[mt[y]] < 0)ds[mt[y]] = ds[x] +1,q.push(mt[y]);
			else if(mt[y]<0)r = true;
		}
	}
	return r;
}
bool dfs(int x){
	for(int y:g[x]){	
		if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
			mt[y] = x;mt2[x] = y;return true;
		}
	}
	ds[x] = 1<<30; return false;
}
int mm(){
	int r = 0;mset(mt,-1); mset(mt2,-1);
	while(bfs())fore(i,0,nn)if(mt2[i] < 0)r+=dfs(i);
	return r;
}

void init(){
	fore(i,0,MAXN)g[i].clear(), ban[i] = 0;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		init();
		ll n,c; cin>>n>>c;
		nn = 1<<n;
		string s1,s2; cin>>s1>>s2;
		ll ini = 0, aux = 1;
		while(SZ(s1)){
			if(s1.back() == s2.back())ini += aux;
			aux*=2;
			s1.pop_back(); s2.pop_back();
		}
		fore(i,0,c){
			string s; cin>>s;
			ll aux = 1;
			ll mask = 0;
			while(SZ(s)){
				if(s.back() == '=') mask+=aux;
				aux*=2;
				s.pop_back();
			}
			ban[mask] = 1;
		}
		fore(i,0,1<<n)aristas(i,n);
		ll mx = mm();
		ban[ini] = 1;
		fore(i,0,1<<n)aristas(i,n);
		cout<<(mx == mm() ? "Bob":"Alice")<<"\n";
	}
	return 0;
}