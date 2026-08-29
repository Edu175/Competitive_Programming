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

typedef long double ld;
const ld EPS = 1e-15l;
const ld pi=atan2l(0,-1),tau=2*pi;

struct pt{
	ld x, y;
	pt(){}
	pt(ld x, ld y) : x(x), y(y) {}
	ld norm2() { return *this * *this; }
	ld norm() { return sqrtl(norm2()); }
	pt operator+(pt p) { return pt(x + p.x, y + p.y); }
	pt operator-(pt p) const { return pt(x - p.x, y - p.y); }
	pt operator*(ld t) { return pt(x * t, y * t); }
	pt operator/(ld t) { return pt(x / t, y / t); }
	ld operator*(pt p) { return x * p.x + y * p.y; }
	ld operator%(pt p) { return x * p.y - y * p.x; }
	pt rot(pt r) { return pt(*this % r, *this * r); }
	pt rot(double a) { return rot(pt(sin(a), cos(a))); }
	ld angle(){return atan2l(y,x);}
	ld angle(pt p){ // a.angle(b): angle from a to b in ccw 
		ld ret=p.angle()-angle();
		if(ret<0)ret+=tau;
		return ret;
	}
	bool operator<(pt p){
		if(abs(x-p.x)>EPS)return x<p.x;
		return y<p.y;
	}
	bool left(pt p, pt q){return (q-p)%(*this-p)>EPS;}
};
pt rot90(pt p) { return pt(-p.y, p.x); }

struct pol{
	int n;
	vector<pt> p;
	pol() {}
	pol(vector<pt> _p){
		p = _p;
		n = SZ(p);
	}
	void normalize(){ // (call before haslog, remove collinear first)
		if(p[2].left(p[0],p[1]))reverse(p.begin(),p.end());
		int pi=min_element(p.begin(),p.end())-p.begin();
		vector<pt> s(n);
		fore(i,0,n)s[i]=p[(pi+i)%n];
		p.swap(s);
	}
	pt farthest(pt v){
		if (n < 10){
			int k = 0;
			fore(i, 1, n) if (v * (p[i] - p[k]) > EPS) k = i;
			return p[k];
		}
		if (n == SZ(p))
			p.pb(p[0]);
		pt a = p[1] - p[0];
		int s = 0, e = n, ua = v * a > EPS;
		if (!ua && v * (p[n - 1] - p[0]) <= EPS)
			return p[0];
		while (1)
		{
			int m = (s + e) / 2;
			pt c = p[m + 1] - p[m];
			int uc = v * c > EPS;
			if (!uc && v * (p[m - 1] - p[m]) <= EPS)
				return p[m];
			if (ua && (!uc || v * (p[s] - p[m]) > EPS))
				e = m;
			else if (ua || uc || v * (p[s] - p[m]) >= -EPS)
				s = m, a = c, ua = uc;
			else
				e = m;
			assert(e > s + 1);
		}
	}
};
pol P;
ld ancho(pt v){
	auto r = P.farthest(v);
	auto l = P.farthest(v * (-1));
	return v * r - v * l;
}
bool valid(pt v) { return v.norm2() >= ancho(v); }

int main(){
	cin.tie(0)->sync_with_stdio(false);
	ll m, w;
	cin >> m >> w;
	vector<pt> p(m);
	fore(i, 0, m){
		cin >> p[i].x >> p[i].y;
		swap(p[i].x, p[i].y);
	}
	P = pol(p); P.normalize();
	vector<pt> vs;
	fore(i, 0, m){
		pt lad = p[(i + 1) % m] - p[i];
		pt v = rot90(lad);
		vs.pb(v);
	}
	vector<ii> exs;
	fore(i, 0, m) fore(j, i + 1, m)if(valid(p[i]-p[j]))exs.pb({i,j}); // O(n)

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
	ll height=round(ancho(pt(0,1)));
	fore(i,0,n){
		ll r=cs[i].snd;
		if(height>cs[i].fst.y-r)ed.pb({s,i});
		if(height>w-cs[i].fst.y-r)ed.pb({i,t});
	}
	// cerr<<"EPS "<<EPS<<"\n";
	fore(i, 0, n) fore(j, i + 1, n){
		pt me = cs[i].fst, he = cs[j].fst;
		ld len=cs[i].snd+cs[j].snd;
		bool pasa = 0;
		for (auto v : vs){
			if (abs((he - me) * v) - len*v.norm() >= ancho(v))
				pasa = 1;
		}
		// if(dbg)cerr<<"dsp perp: "<<pasa<<"\n";
		if(pasa)continue;
		for(auto [k,l]:exs)if(!pasa){
			pt antk = p[k] - p[(k - 1 + m) % m];
			pt sigk = p[(k + 1) % m] - p[k];
			pt antl = p[l] - p[(l - 1 + m) % m];
			pt sigl = p[(l + 1) % m] - p[l];
			antk = rot90(antk);
			sigk = rot90(sigk);
			fore(_, 0, 3) antl = rot90(antl);
			fore(_, 0, 3) sigl = rot90(sigl);
			pt s=(antk.angle(sigk)<antl.angle(sigk)?antk:antl);
			pt e=(antk.angle(sigk)<antk.angle(sigl)?sigk:sigl);
			ld tot=s.angle(e);
			auto val=[&](ld t){
				pt v=s.rot(t);
				ld pol_len=ancho(v);
				ld gap_len=abs((he - me) * v);
				return (gap_len-pol_len)/v.norm();
			};
			ld l=1e-9,r=tot;
			fore(_,0,50)if(!pasa){
				ld h1=l+(r-l)*1/3;
				ld h2=l+(r-l)*2/3;
				// cerr<<l<<","<<r<<": "<<h1<<","<<h2<<"\n";
				ld v1=val(h1),v2=val(h2);
				pasa|=max(v1,v2)>=len-EPS;
				// cerr<<h1<<","<<h2<<": "<<max(val(h1),val(h2))<<" >= "<<len-EPS<<"\n";
				if(v1>v2)r=h2;
				else l=h1;
			}
			// cerr<<l<<","<<r<<": "<<max(val(l),val(r))<<" >= "<<len<<"\n";
		}
		if (!pasa)ed.pb({i, j});
	}
	// for(auto [i,j]:ed)cerr<<i<<","<<j<<"\n";
	ll res=solve(ed, n,s,t);
	cout<<res<<"\n";
}