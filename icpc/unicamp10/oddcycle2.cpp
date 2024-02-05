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
typedef short ll;
typedef pair<ll,ll> ii;
const ll MAXN=105;

vector<ll> ret[MAXN];
ll g[MAXN][MAXN];
ll p[MAXN][2];
ll n;
void bfs(ll a, ll b){
	ll sd; srand((long long)&sd);
	if(!g[a][b])return;
	g[a][b]=g[b][a]=0;
	mset(p,-1);
	queue<ll>q;
	q.push(2*a);
	p[a][0]=-2;
	//cout<<"bfs "<<a<<" "<<b<<"\n";
	while(SZ(q)){
		auto df=q.front(); q.pop();
		bool w=df&1; ll x=df>>1;
		//cout<<x<<" "<<w<<"\n";
		vector<ll>per;
		fore(y,0,n)if(g[x][y]&&p[y][w^1]==-1)per.pb(y);
		random_shuffle(ALL(per));
		for(auto y:per){
			p[y][w^1]=df;
			q.push(2*y+(w^1));
		}
	}
	g[a][b]=g[b][a]=1;
	vector<ll>cyc;
	if(p[b][0]!=-1){
		ll x=2*b;
		while(x!=-2){
			cyc.pb(x/2);
			x=p[x/2][x&1];
		}
	}
	ret[a]=cyc;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		g[i][j]=g[j][i]=c=='Y';
		//if(c=='Y')g[i].pb(j),g[j].pb(i);
	}
	fore(i,0,n)fore(j,0,n)bfs(i,j);
	fore(i,0,n){
		for(auto x:ret[i])cout<<x<<" ";
		cout<<"-1\n";
	}
	return 0;
}
