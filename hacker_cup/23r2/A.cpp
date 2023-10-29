#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3005;

vector<ii>dir={{0,1},{-1,0},{0,-1},{1,0}};

ll n,m;
ii allowed(ll x, ll y, ii d){
	x+=d.fst,y+=d.snd;
	if(x<0||x>=n||y<0||y>=m)return {-1,-1};
	return {x,y};
}

ll qidx=0;
ll q[MAXN*MAXN],sz[MAXN*MAXN];
set<ll>st[MAXN][MAXN];
ll vis[MAXN][MAXN];
char a[MAXN][MAXN];

void dfs(ll x, ll y){
	vis[x][y]=1;
	sz[qidx]++;
	for(auto d:dir){
		auto [xi,yi]=allowed(x,y,d);
		if(xi==-1)continue;
		if(a[xi][yi]=='.'&&!st[xi][yi].count(qidx)){
			q[qidx]++;
			st[xi][yi].insert(qidx);
		}
		else if(a[xi][yi]=='W'&&!vis[xi][yi])dfs(xi,yi);
	}
}

int main(){FIN;
	ll t; cin>>t;
	fore(_,1,t+1){
		cout<<"Case #"<<_<<": ";
		cin>>n>>m;
		fore(i,0,n+3)fore(j,0,m+3){
			st[i][j].clear();
			vis[i][j]=0;
			q[i*n+j]=0;
			sz[i*n+j]=0;
		}
		qidx=0;
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		fore(i,0,n)fore(j,0,m){
			if(a[i][j]=='W'){
				if(vis[i][j])continue;
				qidx++;
				dfs(i,j);
				//cout<<qidx<<": "<<q[qidx]<<" "<<sz[qidx]<<" "<<i<<","<<j<<"\n";
			}
		}
		ll res=0;
		fore(i,0,n)fore(j,0,m){
			if(a[i][j]=='.'){
				ll resi=0;
				for(auto k:st[i][j])if(q[k]==1)resi+=sz[k];
				res=max(res,resi);
			}
		}
		cout<<res<<"\n";
		//if(res)cout<<"YES\n";
		//else cout<<"NO\n";
	}
	return 0;
}
