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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct UnionFind {
	int n,comp;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){ fore(i,0,n)uf[i]=i; }
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		return true;
	}
	int snap(){return SZ(c);}
	void rollback(int snap){
		while(SZ(c)>snap){
			int x=c.back();c.pop_back(); si[uf[x]]-=si[x]; uf[x]=x;comp++;
		}
	}
};
struct Edge{int a, b; ll w;};
struct Node{
    Edge key;
    Node *l, *r;
    ll delta;
    void prop(){
        key.w += delta;
        if(l) l->delta += delta;
        if(r) r-> delta += delta;
        delta = 0;
    }
    Edge top(){prop(); return key;}
};
Node *merge(Node *a, Node *b){
    if(!a || !b) return a ?: b;
    a-> prop(), b -> prop();
    if(a->key.w > b-> key.w) swap(a,b);
    swap(a-> l,(a->r = merge(b,a->r)));
    return a;
}
void pop(Node *& a){a-> prop(); a = merge(a->l,a->r);}
pair<ll,vv> dmst(int n, int r, vector<Edge>&g){
    UnionFind uf(n);
    vector<Node*> heap(n);
    for(Edge e:g) heap[e.b] = merge(heap[e.b], new Node{e});
    ll res = 0;
    vv seen(n,-1), path(n),par(n);
    seen[r] = r;
    vector<Edge> Q(n), in(n,{-1,-1}), comp;
    deque<tuple<int, int, vector<Edge>>> cycs;
    fore(s,0,n){
        int u = s, qi = 0, w;
        while(seen[u] < 0){
            if(!heap[u]) return {-1,{}};
            Edge e = heap[u] -> top();
            heap[u] -> delta -= e.w, pop(heap[u]);
            Q[qi] = e, path[qi++] = u, seen[u]  = s;
            res += e.w, u = uf.find(e.a);
            if(seen[u] == s){
                Node *cyc = 0;
                int end = qi, time = uf.snap();
                do cyc = merge(cyc, heap[w = path[--qi]]);
                while(uf.join(u,w));
                u = uf.find(u), heap[u] = cyc, seen[u] = -1;
                cycs.push_front({u,time,{&Q[qi], &Q[end]}});
            }
        }
        fore(i,0,qi)in[uf.find(Q[i].b)] = Q[i];
    }

    for(auto & asd : cycs){
    	auto &u=get<0>(asd);
		auto &t=get<1>(asd);
		auto &comp=get<2>(asd);
		uf.rollback(t);
        Edge inEdge = in[u];
        for(auto &e : comp) in[uf.find(e.b)] = e;
        in[uf.find(inEdge.b)] = inEdge;
    }
    fore(i,0,n) par[i] = in[i].a;
    return {res,par};
}
vector<int> z_function(const string& s){
	int l=0,r=0,n=SZ(s);
	vector<int> z(SZ(s),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,(ll)z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
int main(){FIN;
	// freopen("dictionary.in","r",stdin);
	// freopen("dictionary.out","w",stdout);
	ll n;
	while(cin>>n){
		assert(n);
		vector<string> a(n);
		fore(i,0,n)cin>>a[i];
		a.pb("."); n++;
		vector<vector<ii>> to(n,vector<ii>(n)); // common, start
		vector<Edge> ed;
		fore(i,0,n)fore(j,0,n)if(i!=j){
			auto z=z_function(a[j]+"$"+a[i]);
			ll m=SZ(a[i]);
			auto &r=to[i][j];
			r={0,m};
			fore(k,0,m){
				ii cur={z[SZ(a[j])+1+k],k};
				r=max(r,cur);
			}
			ed.pb((Edge){i,j,SZ(a[j])-r.fst});
		}
		auto asd=dmst(n,n-1,ed);
		auto cst=asd.fst;
		auto fa=asd.snd;
		assert(fa[n-1]==-1);
		vector<pair<ll,char>> res;
		vector<vv> g(n);
		fore(i,0,n)if(fa[i]!=-1)g[fa[i]].pb(i);
		vector<vv> wh(n);
		function<void(ll)> dfs=[&](ll x) {
			ll s=0;
			ll m=SZ(a[x]);
			wh[x].resize(m);
			if(fa[x]!=-1){
				auto cur=to[fa[x]][x];
				s=cur.fst;
				fore(i,0,s)wh[x][i]=wh[fa[x]][cur.snd+i];
				// cerr<<fa[x]<<"->"<<x<<": "<<cur.fst<<","<<cur.snd<<"\n";
			}
			fore(i,s,m){
				wh[x][i]=SZ(res);
				ll pa=i==0?SZ(res)-1:wh[x][i-1];
				res.pb({pa,a[x][i]});
			}
			for(auto y:g[x])dfs(y);
		};
		dfs(n-1);
		assert(SZ(res)==cst+1);
		cout<<SZ(res)<<"\n";
		for(auto asd:res){
			auto p=asd.fst;
			auto c=asd.snd;
			cout<<p+1;
			if(p!=-1)cout<<" "<<c;
			cout<<"\n";
		}
	}
	return 0;
}
