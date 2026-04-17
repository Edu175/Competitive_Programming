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
const ll maxn=1e4+10;
int col[maxn];
vector<int> g[maxn];
int dst[maxn][maxn];
bool vis[maxn];
void bfs(ll &v){
    queue<ll> q;
    q.push(v);
    mset(vis,0);
    vis[v]=1;
    while(SZ(q)){
        ll u=q.front(); q.pop();
        for(auto w: g[u])if(!vis[w]){
            vis[w]=1; q.push(w);
            dst[w][v]=dst[u][v]+1;
        }
    }
}


int main(){
    JET
    ll n; cin>>n;
    fore(i,0,n) cin>>col[i];
    fore(i,0,n) col[i]--;
    fore(i,0,n-1){
        ll a,b; cin>>a>>b; a--,b--;
        g[col[a]].pb(col[b]);
        g[col[b]].pb(col[a]);
    }
    fore(i,0,n) {
        bfs(i);
    }
    ll q; cin>>q;
    while(q--){
        ll a,b; cin>>a>>b; a--,b--;
        assert(dst[col[a]][col[b]]==dst[col[b]][col[a]]);
        cout<<dst[col[a]][col[b]]<<"\n";
    }
    return 0;
}