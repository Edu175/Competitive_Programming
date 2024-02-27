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
const ll MAXN=1000;
ll n,m;
vector<ii>dir={{0,1},{-1,0},{0,-1},{1,0}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll cv(ii p){return p.fst*m+p.snd;}
ii cv(ll x){return {x/m,x%m};}
char a[MAXN*MAXN];
bool allowed(ii p){
	auto [i,j]=p;
	if(i<0||j<0||i>=n||j>=m||a[cv(p)]=='#')return 0;
	return 1;
}
ll p[MAXN*MAXN],dis[2][MAXN*MAXN];
bool attacked(ll x, ll w){
	if(!w)return 0;
	return (dis[0][x]!=-1&&dis[0][x]<=dis[1][x]);
}

void bfs(vector<ii> s, ll w){
	queue<ii>q;
	for(auto i:s)p[cv(i)]=-2,dis[w][cv(i)]=0,q.push(i);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(d,0,SZ(dir)){
			auto y=x+dir[d];
			if(allowed(y)&&p[cv(y)]==-1){
				dis[w][cv(y)]=dis[w][cv(x)]+1;
				if(attacked(cv(y),w))continue;
				p[cv(y)]=cv(x);
				q.push(y);
			}
		}
	}
}
bool bord(ii x){
	return x.fst==0||x.fst==n-1||x.snd==0||x.snd==m-1;
}
int main(){FIN;
	cin>>n>>m;
	vector<ii>mon;
	ii s=dir[0];
	fore(i,0,n*m){
		cin>>a[i];
		if(a[i]=='M')mon.pb(cv(i));
		if(a[i]=='A')s=cv(i);
	}
	mset(p,-1);
	mset(dis,-1);
	bfs(mon,0);
	mset(p,-1);
	bfs({s},1);
	fore(e,0,n*m)if(allowed(cv(e))&&bord(cv(e))&&p[e]!=-1){
		cout<<"YES\n";
		vector<ii>v;
		for(auto x=e;x!=-2;x=p[x])v.pb(cv(x));
		reverse(ALL(v));
		string let="RULD",path;
		fore(i,0,SZ(v)-1){
			fore(d,0,4)if(v[i]+dir[d]==v[i+1])path.pb(let[d]);
		}
		cout<<SZ(path)<<"\n"<<path<<"\n";
		return 0;
	}
	cout<<"NO\n";
	return 0;
}
