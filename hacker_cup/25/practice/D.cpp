#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN=2e5+5,MAXM=MAXN;
struct edge{
	int y,id;
	list<edge>::iterator rev;
	edge(int y, int id):y(y),id(id){}
};
list<edge> g[MAXN];
void add_edge(int a, int b, int id){
	g[a].push_front(edge(b,id));auto ia=g[a].begin();
	g[b].push_front(edge(a,id));auto ib=g[b].begin();
	ia->rev=ib;ib->rev=ia;
}
vector<edge> p;
void go(int x, bool odd){
    ll iter=0;
	while(odd?SZ(g[x])&1:SZ(g[x])){
        assert(!odd||iter++==0);
		edge e=g[x].front();
		int y=e.y;
		g[y].erase(e.rev);
		g[x].pop_front();
		go(y,odd);
		// cout<<e.y<<","<<e.id<<endl;
		p.pb(e);
	}
}
vector<edge> get_path(int x, bool odd){ // get a path that begins in x, odd for just a path from odd to odd
	p.clear();go(x,odd);reverse(ALL(p));
	return p;
}

ll sq(ll x){return x*x;}

void rota(ll x, vector<edge> &c){
    ll pos=-1;
	fore(i,0,SZ(c))if(c[i].y==x)pos=i;
	pos=(pos+1)%SZ(c);
	rotate(c.begin(),c.begin()+pos,c.end());
}

int main(){FIN;
	ll t; cin>>t;
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		ll n,m; cin>>n>>m;
		vector<ii> ed;
		vv deg(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			add_edge(u,v,i);
			ed.pb({u,v});
			deg[u]++,deg[v]++;
		}
		vector<vector<edge>> ps(n); // paths starting from x
		vector<vector<edge>> cs;
		vv wh(n,-1);
		fore(x,0,n)ps[x]=get_path(x,1);
		vector<ll> per(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){return deg[i]<deg[j];});
		for(auto x:per){
			auto c=get_path(x,0);
			if(!SZ(c))continue;
			assert(c.back().y==x); // cycle
			for(auto e:c)wh[e.y]=SZ(cs);
			cs.pb(c);
		}
		
		ll z=SZ(cs);
		vv vis(z);
		vv col(m,-1);
		fore(x,0,n)if(SZ(ps[x])){
			vector<edge> p;
			ll w=wh[x];
			if(w!=-1&&!vis[w])rota(x,cs[w]),p=cs[w],vis[w]=1;
            // cout<<"ps[x] "<<x<<": ";
            // for(auto e:ps[x])cout<<e.y<<" ";;cout<<"\n";
			for(auto e:ps[x]){
				p.pb(e);
				w=wh[e.y];
				if(w!=-1&&!vis[w]){
					auto &c=cs[w];
                    // cout<<"cycle from "<<e.y<<": ";
                    // for(auto e:c)cout<<e.y<<" ";;cout<<"\n";
					rota(e.y,c);
					for(auto ed:c)p.pb(ed);
                    // for(auto e:c)cout<<e.y<<" ";;cout<<"\n";
					vis[w]=1;
				}
			}
			fore(i,0,SZ(p))col[p[i].id]=i&1;
            // cout<<"path from "<<x<<": ";
            // for(auto e:p)cout<<e.y<<" ";;cout<<"\n";
		}
		fore(i,0,z)if(!vis[i]){
			fore(j,0,SZ(cs[i]))col[cs[i][j].id]=j&1;
		}
		vector<vv> cant(n,vv(2));
		fore(i,0,m){
			assert(col[i]!=-1);
			auto [x,y]=ed[i];
			cant[x][col[i]]++;
			cant[y][col[i]]++;
		}
		ll res=0;
		fore(x,0,n)res+=sq(cant[x][0])+sq(cant[x][1]);
		cout<<res<<" ";
		fore(i,0,m)cout<<col[i]+1;
		cout<<"\n";
	}
	return 0;
}