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
const ll MAXN=1e4+5;

vector<ii> g[MAXN*3];
ll n;

ll cv(ll s, ll i){return 3*s+i;}

pair<ll,vector<ll>> dijkstra(ll s, ll e){
	ll d[3*n],p[3*n];
	mset(d,-1);
	priority_queue<ii> pq;
	fore(i,0,3)d[cv(s,i)]=0,p[cv(s,i)]=-1,pq.push({0,cv(s,i)});
	while(SZ(pq)){
		auto [dx,x]=pq.top(); pq.pop();
		if(d[x]<dx)continue;
		for(auto [y,w]:g[x])if(d[y]==-1||dx+w<d[y]){
			d[y]=dx+w;
			pq.push({d[y],y});
		}
	}
	ll res=-1;
	fore(i,0,3)if(d[cv(e,i)]!=-1){
		if(res==-1||d[cv(e,i)]<res)res=d[cv(e,i)];
	}
	return res; //padres
}
int main(){FIN;
	map<string,ll>mp={{"vegetacion",0},{"grava",1},{"empedrado",2}};
	vector<string>pm={"vegetacion","grava","empedrado"};
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		fore(i,0,3*n+3){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v,w; string s; cin>>u>>v>>w>>s; u--,v--;
			ll ty=mp[s];
			fore(j,0,3)if(j!=ty){
				g[cv(u,j)].pb({cv(v,ty),w});
				g[cv(v,j)].pb({cv(u,ty),w});
			}
		}
		
	}
	return 0;
}
