// what is matter? never mind. 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef int iint;
#define ll long long
#define ull unsigned long long
#define SZ(x) ((int)((x).size())) 
#define ALL(x) (x).begin(),(x).end()
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define db double
#define eb emplace_back
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 500005
#define inf 0x3f3f3f3f
int n,m;
vector <int> G[200005];
int _u[200005],_v[200005];

template <class Q>
void chkmin(Q &x,Q y){
    if(x > y) x = y;
}
queue <int> Q;
int dep[200005],fa[200005];
void psh(int u,int d,int fr){
    if(dep[u] <= d) return;
    dep[u] = d;
    fa[u] = fr;
    Q.push(u);
}

vector <int> son[200005];
int ST[20][200005],dfn[200005],N;
void dfs(int u){
    dfn[u] = ++N;
    ST[0][N] = u;
    for(int v:son[u]) dfs(v);
}

int cmp(int x,int y){
    if(dep[x] < dep[y]) return x;
    return y;
}

int qry(int l,int r){
    int x = __lg(r - l + 1);
    return cmp(ST[x][l],ST[x][r - (1 << x) + 1]);
}

int LCA(int u,int v){
    if(u == v) return u;
    u = dfn[u];v = dfn[v];
    if(u > v) swap(u,v);
    return fa[qry(u + 1,v)];
}
multiset <int> S[200005];
vector <int> P[200005];
int _val[200005];
void dfs2(int u){
    for(int v:son[u]){
        dfs2(v);
        if(SZ(S[u]) < SZ(S[v])) swap(S[u],S[v]);
        for(int val:S[v]) S[u].insert(val);
    }
//    printf("info at %d\n",u);
    for(int v:P[u]){
 //       printf("%d ",v);
        if(v < 0){
            auto it = S[u].find(-v);
            S[u].erase(it);
            it = S[u].find(-v);
            S[u].erase(it);
        }else{
            S[u].insert(v);
        }
    }
//    printf("\n");
    _val[u] = inf;
    if(!S[u].empty()){
        auto it = S[u].begin();
        _val[u] = (*it) - dep[u];
    }
}

int ans[200005];
priority_queue <pii> QQ;
signed main()
{
#ifdef cxy
    freopen("test.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",&_u[i],&_v[i]);
        G[_u[i]].eb(_v[i]);
        G[_v[i]].eb(_u[i]);
    }
    fill(dep,dep + n + 1,inf);
    psh(n,0,0);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v:G[u]) psh(v,dep[u] + 1,u);
    }
/*    rep(u,1,n) printf("%d ",dep[u]);
    printf("\n");
    rep(u,1,n) printf("%d ",fa[u]);
    printf("\n");*/
    rep(u,1,n - 1) son[fa[u]].eb(u);
    dfs(n);
    rep(i,1,17){
        rep(j,1,n){
            if(j + (1 << i) - 1 > n) break;
            ST[i][j] = cmp(ST[i - 1][j],ST[i - 1][j + (1 << (i - 1))]);
        }
    }
    rep(i,1,m){
        if(fa[_u[i]] == _v[i] || fa[_v[i]] == _u[i]) continue;
        int d = LCA(_u[i],_v[i]);
        P[_u[i]].eb(dep[_u[i]] + dep[_v[i]] + 1);
        P[_v[i]].eb(dep[_u[i]] + dep[_v[i]] + 1);
        P[d].eb(-(dep[_u[i]] + dep[_v[i]] + 1));
    }
    dfs2(n);
//    rep(u,1,n) printf("%d ",_val[u]);
//    printf("\n");
    fill(ans,ans + n + 1,inf);
    ans[n] = 0;
    QQ.push(mkp(0,n));
    while(!QQ.empty()){
        pii cur = QQ.top();
        QQ.pop();
        int u = cur.second;
        if(ans[u] < -cur.first) continue;
        for(int v:G[u]){
            if(ans[v] > max(ans[u] + 1,_val[v])){
                ans[v] = max(ans[u] + 1,_val[v]);
                QQ.push(mkp(-ans[v],v));
            }
            
        }
    }
    if(ans[1] > 5 * n) printf("-1\n");
    else printf("%d\n",ans[1]);
    return 0;
}
/*
g++ EE.cpp -Wall -Dcxy -Wshadow -O2 -Wno-unused-result -o EE
*/
