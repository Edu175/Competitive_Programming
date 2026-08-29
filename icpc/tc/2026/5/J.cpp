#include <bits/stdc++.h>

#include <cassert>
#define pb push_back
#define fst first
#define snd second
#define fore(i, a, b) for (ll i = a, jet = b; i < jet; i++)
#define SZ(x) ll(x.size())
#define ALL(x) x.begin(), x.end()
#define mset(a, v) memset((a), (v), sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;

const ll INF = 1e18;

struct Dinic{
	int nodes, src, dst;
	vector<int> dist, q, work;
	struct edge{
		int to, rev;
		ll f, cap;
	};
	vector<vector<edge>> g;
	Dinic(int x) : nodes(x), dist(x), q(x), work(x), g(x) {}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t, SZ(g[t]), 0, cap});
		g[t].pb((edge){s, SZ(g[s]) - 1, 0, 0});
		// cerr<<"add edge "<<s<<" -> "<<t<<" ("<<cap<<")\n";
	}
	bool dinic_bfs(){
		fill(ALL(dist), -1);
		dist[src] = 0;
		int qt = 0;
		q[qt++] = src;
		for (int qh = 0; qh < qt; qh++){
			int u = q[qh];
			fore(i, 0, SZ(g[u]))
			{
				edge &e = g[u][i];
				int v = g[u][i].to;
				if (dist[v] < 0 && e.f < e.cap)
					dist[v] = dist[u] + 1, q[qt++] = v;
			}
		}
		return dist[dst] >= 0;
	}

	ll dinic_dfs(int u, ll f){
		if (u == dst)
			return f;
		for (int &i = work[u]; i < SZ(g[u]); i++)
		{
			edge &e = g[u][i];
			if (e.cap <= e.f)
				continue;
			int v = e.to;
			if (dist[v] == dist[u] + 1)
			{
				ll df = dinic_dfs(v, min(f, e.cap - e.f));
				if (df > 0)
				{
					e.f += df;
					g[v][e.rev].f -= df;
					return df;
				}
			}
		}
		return 0;
	}

	ll max_flow(int _src, int _dst){
		src = _src, dst = _dst;
		ll result = 0;
		while (dinic_bfs())
		{
			fill(ALL(work), 0);
			while (ll delta = dinic_dfs(src, INF))
			result += delta;
		}
		return result;
	}
};

ll solve(const vector<ii> &ed, int n, int s, int t){
	Dinic dn(2 * n + 2);
	fore(u, 0, n) dn.add_edge(2 * u, 2 * u + 1, 1);
	ll s_new=2*n,t_new=s_new+1;
	for (auto [u, v] : ed){ // asume que no existe arista s->t
		fore(_,0,2)if(v!=s&&u!=t){
			if (u == s)
			{
				dn.add_edge(s_new, 2 * v, INF);
			}
			else if (v == t)
			{
				dn.add_edge(2 * u + 1, t_new, INF);
			}
			else
			{
				dn.add_edge(2 * u + 1, 2 * v, INF);
			}
			swap(u,v);
		}
	}
	return dn.max_flow(s_new, t_new);
}

#define str to_string
const ll EPS=0;
struct pt{
	ll x, y;
	pt(){}
	pt(ll x, ll y) : x(x), y(y) {}
	ll norm2() { return *this * *this; }
	pt operator+(pt p) { return pt(x + p.x, y + p.y); }
	pt operator-(pt p) const { return pt(x - p.x, y - p.y); }
	pt operator*(ll t) { return pt(x * t, y * t); }
	ll operator*(pt p) { return x * p.x + y * p.y; }
	ll operator%(pt p) { return x * p.y - y * p.x; }
	bool operator<(pt p){
		if(abs(x-p.x)>EPS)return x<p.x;
		return y<p.y;
	}
	bool left(pt p, pt q){return (q-p)%(*this-p)>EPS;}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
};
// string cv(pt a){return str(a.x)+","+str(a.y);}
vector<pt> chull(vector<pt> p){// CCW order
	if(SZ(p)<3) return p;
	vector<pt> r; sort(ALL(p)); int k=0;
	fore(_,0,2){//first lower hull, then upper hull
		fore(i,0,SZ(p)){
			while(SZ(r)>1+k&&r.back().leftOrAt(r[SZ(r)-2],p[i]))r.pop_back();
			r.pb(p[i]);
		}
        r.pop_back(),k=SZ(r),reverse(ALL(p));
	}
	return r;
}
vector<pt> minkowski_sum(vector<pt> a, vector<pt> b, bool dochul){
	vector<pt> c;
	fore(i,0,SZ(a))fore(j,0,SZ(b))c.pb(a[i]+b[j]);
	return dochul?chull(c):c;
}
vector<pt> neg(vector<pt> a){
	for(auto &i:a)i=i*(-1);
	return a;
}
int sgn(ll x){return x<-EPS?-1:x>EPS;}
pt o(0,0);
typedef __int128 xl;
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	ll collidea(ll len){ // con origen
		bool inside=1;
		fore(i,0,n){
			pt me=p[i],he=p[(i+1)%n];
			inside&=o.leftOrAt(me,he);
		}
		if(inside)return 1;
		fore(i,0,n){
			pt me=p[i],he=p[(i+1)%n];
			pt d=he-me;
			if((o-me)*d>0&&(o-he)*d<0){
				xl dis=abs(d%(o-me));
				dis*=dis;
				if(dis<xl(len)*len*d.norm2())return 1;
			}
			else {
				ll dis=min(me.norm2(),he.norm2());
				if(dis<len*len)return 1;
			}
		}
		return 0;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);
	ll m, w;
	cin >> m >> w;
	vector<pt> p(m);
	fore(i, 0, m){
		ll x,y; cin>>x>>y;
		p[i]=pt(x,y);
		swap(p[i].x, p[i].y);
	}

	ll n; cin >> n;
	vector<pair<pt, ll>> cs(n);
	fore(i, 0, n){
		ll x, y, r;
		cin >> x >> y >> r;
		swap(x, y);
		cs[i] = {{x, y}, r};
	}
	vector<ii> ed;
	ll s = n, t = n + 1;
	ll mxy=-100,mny=w+100;
	fore(i,0,m){
		mxy=max(mxy,(ll)p[i].y);
		mny=min(mny,(ll)p[i].y);
	}
	ll height=mxy-mny;
	fore(i,0,n){
		ll r=cs[i].snd;
		if(height>cs[i].fst.y-r)ed.pb({s,i});
		if(height>w-cs[i].fst.y-r)ed.pb({i,t});
	}
	auto segs=minkowski_sum(p,neg(p),1);
	
	fore(i, 0, n) fore(j, i + 1, n){
		pt me = cs[i].fst, he = cs[j].fst;
		auto T=pol(minkowski_sum(segs,{he-me},0));
		ll len=cs[i].snd+cs[j].snd;
		bool nopasa=T.collidea(len);
		if (nopasa)ed.pb({i, j});
	}
	// for(auto [i,j]:ed)cerr<<i<<","<<j<<"\n";
	ll res=solve(ed, n,s,t);
	cout<<res<<"\n";
}