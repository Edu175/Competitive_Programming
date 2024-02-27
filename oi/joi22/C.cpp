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
const ll MAXN=6e6+5;

ll a[MAXN];
ll n,m,k;
ll cv(ii x){return m*x.fst+x.snd;}
ii cv(ll x){return {x/m,x%m};}
vector<ii>dir={{0,1},{-1,0},{0,-1},{1,0}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
void operator+=(ii &a, ii b){a=a+b;}
bool allowed(ii p){
	auto [i,j]=p;
	if(i<0||i>=n||j<0||j>=m)return 0;
	return 1;
}
ll d[MAXN],vis[MAXN];
deque<ii>q;
void go(ii x, ii y, ll g=0){
	if(!allowed(y)||(!g&&a[cv(y)]))return;
	ll nd=d[cv(x)]+g;
	if(d[cv(y)]!=-1&&d[cv(y)]<=nd)return;
	d[cv(y)]=nd;
	if(!g)q.push_front(y);
	else q.pb(y);
}
ll reach(ii x, ii e){
	return (max(abs(x.fst-e.fst),abs(x.snd-e.snd))<=k&&
	       abs(x.fst-e.fst)+abs(x.snd-e.snd)<2*k);
}

ll bfs(ii s, ii e){
	mset(d,-1);
	d[cv(s)]=0;
	q.push_front(s);
	while(SZ(q)){
		auto x=q.front(); q.pop_front();
		if(vis[cv(x)])continue;
		vis[cv(x)]=1;
		for(auto add:dir){
			auto y=x+add;
			go(x,y);
		}
		// continue; // sb1
		auto [i,j]=x;
		if(reach(x,e))go(x,e,1);
		for(ii y={i-k,j-k+1};y.snd<j+k;y+=dir[0])go(x,y,1);
		for(ii y={i+k,j-k+1};y.snd<j+k;y+=dir[0])go(x,y,1);
		for(ii y={i-k+1,j-k};y.fst<i+k;y+=dir[3])go(x,y,1);
		for(ii y={i-k+1,j+k};y.fst<i+k;y+=dir[3])go(x,y,1);
	}
	return d[cv(e)];
}

int main(){FIN;
	cin>>n>>m>>k;
	ii s,e; cin>>s.fst>>s.snd>>e.fst>>e.snd; s.fst--,s.snd--,e.fst--,e.snd--;
	fore(i,0,n*m){
		char c; cin>>c;
		a[i]=(c=='#');
	}
	cout<<bfs(s,e)<<"\n";
	return 0;
}
