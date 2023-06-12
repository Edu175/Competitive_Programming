#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

const ll MAXN=1e3+5,INF=1e3*2+5;

vector<pair<ll,ll>>dir={{-1,0},{0,-1},{0,1},{1,0}};
pair<ll,ll> operator+(pair<ll,ll>p1 , pair<ll,ll> p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}

char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll d[MAXN][MAXN];

void bfs(pair<ll,ll> e){
	queue<pair<ll,ll>>q;
	q.push(e);
	vis[e.fst][e.snd]=1;
	d[e.fst][e.snd]=0;
	while(SZ(q)){
		auto f=q.front();
		q.pop();
		for(auto i:dir){
			pair<ll,ll> fi=f+i;
			if((fi.fst>=0&&fi.snd>=0)&&(a[fi.fst][fi.snd]!='T')){
				if(!vis[fi.fst][fi.snd]){
					q.push(fi);
					vis[fi.fst][fi.snd]=1;
					d[fi.fst][fi.snd]=d[f.fst][f.snd]+1;
				}
			}
		}
	}
}


int main(){FIN;
	ll n,m; cin>>n>>m;
	pair<ll,ll> e,s;
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
			if(a[i][j]=='E')e={i,j};
			if(a[i][j]=='S')s={i,j};
		}
		a[i][m]='T';
	}
	fore(j,0,m+1)a[n][j]='T';
	bfs(e);
	//cout<<s.fst<<","<<s.snd<<": "<<d[s.fst][s.snd]<<"\n";
	ll res=0;
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]>'0'&&a[i][j]<='9'){
				//cout<<i<<","<<j<<": "<<d[i][j]<<" v="<<a[i][j]-'0'<<"\n";
				if(vis[i][j]&&d[i][j]<=d[s.fst][s.snd])res+=a[i][j]-'0';
			}
		}
	}
	pres;
	return 0;
}
