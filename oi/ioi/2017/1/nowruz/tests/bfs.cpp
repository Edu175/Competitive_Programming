#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhg:v)cout<<dfhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=1024*1024+5;

ll n,m;
ii cv(ll x){return {x/m,x%m};}
ll cv(ii x){return x.fst*m+x.snd;}
char a[MAXN];
bool vis[MAXN];
vector<ii> dir={{1,0},{0,1},{-1,0},{0,-1}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
bool allowed(ii x){
	return x.fst>=0&&x.fst<n&&x.snd>=0&&x.snd<m;
}
ll num(ll x){
	auto i=cv(x);
	ll res=0;
	for(auto d:dir){
		auto j=d+i;
		if(!allowed(j))continue;
		auto y=cv(j);
		res+=a[y]=='.'&&vis[y];
	}
	return res;
}
void bfs(ll s){
	queue<ll>q;
	vis[s]=1;
	q.push(s);
	while(SZ(q)){
		auto x=q.front();q.pop();
		auto i=cv(x);
		random_shuffle(ALL(dir));
		for(auto d:dir){
			auto j=d+i;
			if(!allowed(j))continue;
			auto y=cv(j);
			if(a[y]=='#'||vis[y])continue;
			if(num(y)>1)a[y]='X';
			else q.push(y);
			vis[y]=1;
		}
	}
}
// void dfs(ll x){
// 	vis[x]=1;
// 	if(num(x)>1){a[x]='X';return;}
// 	auto i=cv(x);
// 	random_shuffle(ALL(dir));
// 	for(auto d:dir){
// 		auto j=d+i;
// 		if(!allowed(j))continue;
// 		auto y=cv(j);
// 		if(a[y]=='#'||vis[y])continue;
// 		dfs(y);
		
// 	}
// }
ll start(ll s){
	fore(x,0,n*m){
		if(a[x]!='#')a[x]='.';
		vis[x]=1;
	}
	// cout<<"start "<<s<<":\n";
	// fore(i,0,n){
	// 	fore(j,0,m)cout<<a[cv({i,j})];
	// 	cout<<"\n";
	// }
	assert(a[s]!='#');
	mset(vis,0);
	bfs(s);
	ll res=0;
	fore(x,0,n*m){
		if(!vis[x]&&a[x]=='.')a[x]='X';
		if(a[x]=='.')res+=num(x)==1;
	}
	// cout<<"res "<<res<<"\n";
	// fore(i,0,n){
	// 	fore(j,0,m)cout<<a[cv({i,j})];
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	return res;
}
double LIMIT=150;
int main(){FIN;
	cin>>n>>m;
	ll k; cin>>k;
	ll sd; srand((long long)&sd);
	fore(i,0,n*m)cin>>a[i];
	vector<ll>free;
	fore(x,0,n*m)if(a[x]=='.')free.pb(x);
	random_shuffle(ALL(free));
	vector<char>b(n*m);
	ll res=-1;
	for(auto x:free){
		if(res>=k||clock()>=LIMIT*CLOCKS_PER_SEC)break;
		ll resi=start(x);
		if(resi>res){
			res=resi;
			fore(x,0,n*m)b[x]=a[x];
		}
	}
	cerr<<"found "<<res<<" out of "<<k<<"\n";
	fore(i,0,n){
		fore(j,0,m)cout<<b[cv({i,j})];
		cout<<"\n";
	}
	
}