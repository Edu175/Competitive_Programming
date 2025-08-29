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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=500; // VER
const ll MAXN=1e5+5;
vector<ii> apa[MAXN]; // O(2n) amortizado

ll cnt=0;
ll col[MAXN],D[MAXN],S[MAXN];
vv g[MAXN];
vv ord;

void dfs1(ll x, ll fa){
    apa[col[x]].pb({cnt,x});
    ord.pb(x);
    S[x]=cnt;
    cnt++;
    for(auto y:g[x])if(y!=fa){
        D[y]=D[x]+1;
        dfs1(y,x);
        apa[col[x]].pb({cnt++,x});
        ord.pb(x);
    }
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
    vv nod;
    big[c]=1;
    fore(i,0,n)if(col[i]==c)nod.pb(i);
    auto d=bfs(nod);
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
    ll l=S[x],r=S[y];
    if(l>r)swap(l,r);
    ll p=st_query(l,r+1);
    if(x==y)assert(p==x);
    return p;
}

ll dame(ll x, ll y){
    ll p=lca(x,y);
    ll res=D[x]+D[y]-2*D[p];
    // cout<<"dame "<<x<<" "<<y<<": "<<p<<": "<<res<<"\n";
    return res;
}

vv merge(ll a, ll b){
    auto u=apa[a],v=apa[b];
    vv ret;
    ll l=0,r=0;
    while(l<SZ(u)||r<SZ(v)){
        ll w=0;
        if(l==SZ(u)||(r<SZ(v)&&v[r].fst<u[l].fst))w=1;
        if(!w)ret.pb(u[l++].snd);
        else ret.pb(v[r++].snd);
    }
    return ret;
}

vv t[MAXN];
ii dfs2()

ll fix(vv a){
    fore(i,0,SZ(a)-1)if(col[a[i]]!=col[a[i+1]]){
        ll l=i,r=i+1;
        ll p=lca(a[l],a[r]);
        ll da=D[a[l]],db=D[a[r]];
        while(l>0&&col[l-1]==col[l]&&lca(a[l-1],a[r])==p)da=min(da,D[--l]);
        while(r<SZ(a)&&col[r]==col[r+1]&&lca(a[l],a[r+1])==p)db=min(db,D[++r]);
    }
}

ll query(ll x, ll y){
    ll a=col[x],b=col[y];
    if(a==b)return 0;
    if(big[b])swap(a,b);
    // cout<<"\n\nquery "<<a<<" "<<b<<":\n";
    if(big[a]){
        return dis[a][b];
    }
    // cout<<"nobig\n";
    auto v=merge(a,b);
    // for(auto i:v)cout<<i<<" ";;cout<<"\n";
    ll mn=n+5;
    fore(i,0,SZ(v)-1){
        ll x=v[i],y=v[i+1];
        if(col[x]!=col[y])mn=min(mn,dame(x,y));
    }
    // cout<<"= ";
    return mn;
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
    fore(c,0,n)if(SZ(apa[c])){
        if(SZ(apa[c])>=B)dobig(c);
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