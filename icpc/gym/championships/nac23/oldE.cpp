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
typedef array<array<ll,3>,3> Graph;

Graph g;
map<pair<ll,Graph>,bool> dp;

bool f(ll x, Graph a){ // is it winning
	if(dp.count({x,a}))return dp[{x,a}];
	auto &res=dp[{x,a}];
	res=0;
	fore(y,0,3)if(a[x][y]<g[x][y]){
		a[x][y]++;
		res|=!f(y,a);
		a[x][y]--;
	}
	return res;
}

bool solve(ll n, Graph _g, ll s){ // is it winning from s
	g=_g;
	fore(i,0,3){
		g[i][i]%=2;
		ll j=(i+1)%3;
		ll q=min(g[i][j],g[j][i]);
		g[i][j]-=q;
		g[j][i]-=q;
	}
	// cerr<<"solve "<<s<<"\n";
	// fore(i,0,3){
	// 	fore(j,0,3)cerr<<g[i][j]<<" ";
	// 	cerr<<"\n";
	// }
	
	auto hayCyc=[&](){
		ll ret=1;
		fore(i,0,3)ret&=g[i][(i+1)%3]>0;
		return ret;
	};
	if(n>2&&!hayCyc()){ // reversea
		fore(i,0,3)reverse(ALL(g[i]));
		swap(g[0],g[2]);
		s=2-s;
	}
	ll fg=hayCyc();
	ll mn=g[2][0];
	fore(i,0,2)mn=min(mn,g[i][i+1]);
	fg&=mn>=5;
	// cerr<<"fg "<<fg<<"\n";
	if(!fg){
		dp.clear();
		ll res=f(s,Graph{});
		// cerr<<"solve\n";
		// fore(i,0,3){
		// 	fore(j,0,3)cerr<<g[i][j]<<" ";
		// 	cerr<<"\n";
		// }
		// cerr<<"= "<<res<<"\n\n";
		return res;
	}
	ll cant=mn*3;
	fore(i,0,3)cant+=g[i][i];
	for(ll i=s;g[i][(i+1)%3]>mn;i=(i+1)%3)cant++;
	return (cant%2);
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
	// fore(i,0,3)show(g[i])
	ll n=SZ(let);
	assert(n<=3);
	ll res=0;
	fore(i,0,3)fore(j,0,3)if(g[i][j]){
		ll coef=g[i][j];
		g[i][j]--;
		res+=coef*(!solve(n,g,j)); // quiero que bob pierda
		g[i][j]++;
	}
	cout<<res<<"\n";
	return 0;
}