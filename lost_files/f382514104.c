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
const ll MAXN=405;

ii operator+(ii p1,ii p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}

bool vis[MAXN][MAXN];
ll d[MAXN][MAXN];
vector<ii>dir={{1,1},{-1,1},{1,-1},{-1,-1}};
vector<ii>mov;
ll n;

bool allowed(ii p){
	ll flag=1;
	if(p.fst<0)flag=0;
	if(p.fst>=n)flag=0;
	if(p.snd<0)flag=0;
	if(p.snd>=n)flag=0;
	return flag;
}

void bfs(ii x){
	queue<ii> q;
	q.push(x);
	vis[x.fst][x.snd]=1;
	d[x.fst][x.snd]=0;
	while(SZ(q)){
		auto f=q.front();
		q.pop();
		for(auto i:mov){
			for(auto j:dir){
				ii y={f.fst+i.fst*j.fst,f.snd+i.snd*j.snd};
				//cout<<y.fst<<" "<<y.snd<<": ";
				if(allowed(y)&&!vis[y.fst][y.snd]){
					//cout<<"done\n";
					q.push(y);
					vis[y.fst][y.snd]=1;
					d[y.fst][y.snd]=d[f.fst][f.snd]+1;
				}
				/*else {
					if(!allowed(y))cout<<"out\n";
					else cout<<"vis\n";
				}*/
			}
		}
	}
}

int main(){FIN;
	ll m; cin>>n>>m;
	set<ll> sq;
	fore(i,0,n)sq.insert(i*i);
	for(auto i:sq){
		if(sq.count(m-i))mov.pb({sqrt(i),sqrt(m-i)});
	}
	//for(auto i:mov)cout<<i.fst<<" "<<i.snd<<"\n";
	mset(d,-1);
	bfs({0,0});
	//cout<<"\n";
	fore(i,0,n){
		fore(j,0,n)cout<<d[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
