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

const int maxn=1e5+5;
vector<ii> g[maxn];
ll d[maxn];
ii puntos[maxn];


ll dist(ll x,ll y){
	return (abs(puntos[x].fst-puntos[y].fst)+abs(puntos[x].snd-puntos[y].snd));
}

void dijkstra(ll x){
	d[x]=0;
	priority_queue<ii,vector<ii>,greater<ii>> q;
	q.push({0,x});
	while(SZ(q)){
		x=q.top().snd; auto c=q.top().fst;
		q.pop();
		if(d[x]!=c) continue;
		for(auto i:g[x]){
			ll y=i.fst,c=i.snd;
			if(d[y]==-1||d[x]+c<d[y]){
				d[y]=d[x]+c;
				q.push({d[y],y});
			}
		}
	}
	
}

int main(){
	JET
	mset(d,-1);
	ll n,k;
	cin>>n>>k;
	ll x,y,x1,y1;
	cin>>x>>y>>x1>>y1;
	x--;y--;x1--;y1--;
	puntos[0]={x,y};
	puntos[1]={x1,y1};
	g[0].pb({1,dist(0,1)});
	vector<ii> cercfilas;
	vector<ii> cerccol;
	
	fore(i,0,k){
		int a,b; cin>>a>>b;
		a--;b--;
		puntos[i+2]={a,b};
		g[0].pb({i+2,min(abs(x-a),abs(y-b))});
		cercfilas.pb({b,i+2});
		cerccol.pb({a,i+2});
		g[i+2].pb({1,dist(i+2,1)});
	}
	sort(ALL(cerccol));
	sort(ALL(cercfilas));
	auto it=lower_bound(ALL(cerccol),ii({puntos[0].fst,-1}));
	if(it!=cerccol.end()){
		g[0].pb({it->snd,abs(it->fst-puntos[0].fst)});
	}
	if(it!=cerccol.begin()){
		it--;
		g[0].pb({it->snd,abs(it->fst-puntos[0].fst)});
	}
	
	it=lower_bound(ALL(cercfilas),ii({puntos[0].snd,-1}));
	if(it!=cercfilas.end()){
		g[0].pb({it->snd,abs(it->fst-puntos[0].snd)});
	}
	if(it!=cercfilas.begin()){
		it--;
		g[0].pb({it->snd,abs(it->fst-puntos[0].snd)});
	}
	
	#define nf i
	
	fore(i,2,k+2){
		auto it=upper_bound(ALL(cerccol),ii({puntos[i].fst,nf}));
		if(it!=cerccol.end()){
			g[i].pb({it->snd,abs(it->fst-puntos[i].fst)});
		}
		it--;
		if(it!=cerccol.begin()){
			it--;
			g[i].pb({it->snd,abs(it->fst-puntos[i].fst)});
		}
		
		it=upper_bound(ALL(cercfilas),ii({puntos[i].snd,nf}));
		if(it!=cercfilas.end()){
			g[i].pb({it->snd,abs(it->fst-puntos[i].snd)});
		}
		it--;
		if(it!=cercfilas.begin()){
			it--;
			g[i].pb({it->snd,abs(it->fst-puntos[i].snd)});
		}
	}
	dijkstra(0);
	cout<<d[1]<<"\n";
	
}