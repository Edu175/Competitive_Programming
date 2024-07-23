#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn=1005;
vector<ii> g[maxn*maxn+5];

int parse(int i,int j){
	return i*maxn+j;
}

int dist(ii a, ii b){
	return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}

ii d[maxn*maxn+5];

void dijkstra(ll x){
	d[x]={0,-1};
	priority_queue<ii,vector<ii>,greater<ii>> q;
	q.push({0,x});
	while(SZ(q)){
		x=q.top().snd; auto c=q.top().fst;
		q.pop();
		if(d[x].fst!=c) continue;
		for(auto i:g[x]){
			ll y=i.fst,c=i.snd;
			if(d[y].fst==-1||d[x].fst+c<d[y].fst){
				d[y].fst=d[x].fst+c;
				q.push({d[y].fst,y});
				d[y].snd=x;
			}
		}
	}
	
}

int main(){
	fore(i,0,maxn*maxn+5) d[i]={-1,0};
	int n,k; cin>>n>>k;
	fore(i,0,n){
		fore(j,0,n){
			if(i>0) g[parse(i,j)].pb({parse(i-1,j),1});
			if(i<maxn-1) g[parse(i+1,j)].pb({parse(i+1,j),1});
			if(j>0) g[parse(i,j)].pb({parse(i,j-1),1});
			if(j<maxn-1) g[parse(i,j+1)].pb({parse(i,j+1),1});
		}
	}
	int x,y,x1,y1; cin>>x>>y>>x1>>y1;
	x--;y--;x1--;y1--;
	ii final={x1,y1};
	ii principio={x,y};
	g[parse(principio.fst,principio.snd)].pb({parse(final.fst,final.snd),dist(principio,final)});
	fore(i,0,k){
		int a,b; cin>>a>>b;a--;b--;
		g[parse(a,b)].pb({parse(final.fst,final.snd),dist({a,b},final)});
		fore(j,0,maxn){
			g[parse(j,b)].pb({parse(a,b),0});
		}
		fore(j,0,maxn){
			g[parse(a,j)].pb({parse(a,b),0});
		}
	}
	dijkstra(parse(principio.fst,principio.snd));
	cout<<d[parse(final.fst,final.snd)].fst<<"\n";
}