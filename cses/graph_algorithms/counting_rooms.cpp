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
char a[MAXN*MAXN];
bool allowed(ii p){
	auto [i,j]=p;
	if(i<0||j<0||i>=n||j>=m||a[cv(p)]=='#')return 0;
	return 1;
}
ll vis[MAXN*MAXN];
void bfs(ii s){
	queue<ii>q;
	vis[cv(s)]=1;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto d:dir){
			auto y=x+d;
			if(allowed(y)&&!vis[cv(y)]){
				vis[cv(y)]=1;
				q.push(y);
			}
		}
	}
}
int main(){FIN;
	cin>>n>>m;
	fore(i,0,n*m)cin>>a[i];
	ll res=0;
	fore(i,0,n)fore(j,0,m)if(!vis[cv({i,j})]&&allowed({i,j})){
		bfs({i,j});
		res++;
	}
	cout<<res<<"\n";
	return 0;
}
