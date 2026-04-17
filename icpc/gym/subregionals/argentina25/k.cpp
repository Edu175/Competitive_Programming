#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=90; // VER
const ll MAXN=1e5+5;

ll cnt=0;
ll col[MAXN],D[MAXN],P[MAXN],S[MAXN];
vv nod[MAXN];
vv g[MAXN];
vv ord;

void dfs1(ll x, ll fa){
    P[x]=SZ(ord);
    ord.pb(x);
    nod[col[x]].pb(x);
    S[x]=cnt++;
    for(auto y:g[x])if(y!=fa){
        D[y]=D[x]+1;
        dfs1(y,x);
        ord.pb(x);
    }
    // E[x]=cnt;
}

ll big[MAXN];

vector<int> dis[MAXN]; // to colors
ll n;
vv bfs(vv s){
    vv dist(n,-1);
    queue<ll> q;
    for(auto x:s){
        dist[x] = 0;
        q.push(x);
    }
    while(SZ(q)){
        ll y = q.front();q.pop();
        for(auto k:g[y]){
            if(dist[k] == -1){
                dist[k] = dist[y] + 1;
                q.push(k);
            }
        }
    }
    return dist;
}
#define minig(a,b) a=min(a,b)
void dobig(ll c){ // O(n)
    big[c]=1;
    auto d=bfs(nod[c]);
    dis[c]=vector<int>(n,n+5);
    fore(i,0,n)minig(dis[c][col[i]],(int)d[i]);
}

ll oper(ll i, ll j){return D[i]<D[j]?i:j;}

const ll K=18;
int st[K][1<<K];
void st_init(vv a){
    ll n=SZ(a);
    fore(i,0,n)st[0][i]=a[i];
    fore(k,1,K)fore(i,0,n-(1<<k)+1){
        st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
    }
}
int st_query(int s, int e){
    int k=__lg(e-s);
    return oper(st[k][s],st[k][e-(1<<k)]);
}

ll lca(ll x, ll y){
    ll l=P[x],r=P[y];
    if(l>r)swap(l,r);
    ll p=st_query(l,r+1);
    if(x==y)assert(p==x);
    return p;
}

// acordate de limpiarlos:
vv t[MAXN];
ll ca,cb;
ll res;
ii dfs2(ll x){
    ii d={2*n+5,2*n+5};
    if(col[x]==ca)d.fst=D[x];
    if(col[x]==cb)d.snd=D[x];
    for(auto y:t[x]){
        auto cur=dfs2(y);
        minig(d.fst,cur.fst);
        minig(d.snd,cur.snd);
    }
    res=min(res,d.fst+d.snd-2*D[x]);
    return d;
}

vv merge(ll a, ll b){
    auto u=nod[a],v=nod[b];
    vv ret;
    ll l=0,r=0;
    while(l<SZ(u)||r<SZ(v)){
        ll w=0;
        if(l==SZ(u)||(r<SZ(v)&&S[v[r]]<S[u[l]]))w=1;
        if(!w)ret.pb(u[l++]);
        else ret.pb(v[r++]);
    }
    return ret;
}

void add_edge(ll x, ll y){if(y!=-1)t[x].pb(y);}
ll query(ll x, ll y){
    ll a=col[x],b=col[y];
    if(a==b)return 0;
    if(big[b])swap(a,b);
    if(big[a])return dis[a][b];
    // me armo el virtual tree
    auto v=merge(a,b);
    stack<ll>s; s.push(v[0]); ll ult=-1,p;
	auto vacia=[&](bool fg){ // adds edges between removed
		while(SZ(s)&&(fg||lca(s.top(),p)!=s.top())){
			add_edge(s.top(),ult);
			ult=s.top(); s.pop();
		}
	};
	vv virt; // virtual nodes and possibly normal
    fore(i,1,SZ(v)){
		ll x=v[i]; p=lca(s.top(),x); virt.pb(p);
		vacia(0);
		if(s.empty()||p!=s.top())s.push(p);
		add_edge(p,ult); ult=-1;
		if(p!=x)s.push(x);
	}
	vacia(1);
	ll rt=ult; // root is last popped
	// doit
    ca=a,cb=b;
    res=n+5;
    dfs2(rt);
    for(auto a:{v,virt})for(auto i:a)t[i].clear();
    return res;
}

int main(){
    JET
    cin>>n;
    fore(i,0,n)cin>>col[i],col[i]--;
    fore(i,0,n-1){
        ll u,v; cin>>u>>v; u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(0,-1);
    fore(c,0,n)if(SZ(nod[c])){
        if(SZ(nod[c])>=B)dobig(c);
    }
    assert((1<<K)>SZ(ord));
    st_init(ord);
    ll q; cin>>q;
    while(q--){
        ll x,y; cin>>x>>y; x--,y--;
        cout<<query(x,y)<<"\n";
    }
    return 0;
}