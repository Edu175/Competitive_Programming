#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<endl;}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef array<array<ll,3>,3> Graph;

Graph g;

ll f(ll x, Graph a){ // is it winning
	ll res=0;
	fore(y,0,3)if(a[x][y]<g[x][y]){
		a[x][y]++;
		// if(!f(y,a))return 1;
		res|=!f(y,a);
		a[x][y]--;
		// if(!res)return 1;
	}
	return res;
}

bool solve(Graph _g, ll s){ // is it winning from s
	g=_g;
	fore(i,0,3){
		g[i][i]%=2;
		ll j=(i+1)%3;
		ll q=min(g[i][j],g[j][i]);
		g[i][j]-=q;
		g[j][i]-=q;
	}
	return f(s,Graph{});
}

int main(){
	JET
	vector<char> let;
	vector<pair<char,char>> ed;
	ll m; cin>>m;
	fore(i,0,m){
		string s; cin>>s;
		char u=s[0],v=s.back();
		let.pb(u);
		let.pb(v);
		ed.pb({u,v});
	}
	sort(ALL(let)); let.resize(unique(ALL(let))-let.begin());
	Graph g{};
	for(auto [a,b]:ed){
		ll u=find(ALL(let),a)-let.begin();
		ll v=find(ALL(let),b)-let.begin();
		g[u][v]++;
	}
	g=Graph{
		array<ll,3>({1,0,330}),
		{330,1,0},
		{0,330,1}
	};
	fore(i,0,3)show(g[i])
	assert(SZ(let)<=3);
	ll res=0;
	fore(i,0,3)fore(j,0,3)if(g[i][j]){
		ll coef=g[i][j];
		g[i][j]--;
		res+=coef*(!solve(g,j)); // quiero que bob pierda
		g[i][j]++;
	}
	cout<<res<<"\n";
	return 0;
}