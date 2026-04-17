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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef map<ll,ll> table;
const ll MAXN=2e5+5,K=18;

void cand(ll &mx, ll &dis, ll s, ll d){
    if(s<mx)return;
    if(s>mx||d<dis)mx=s,dis=d;
}
struct node{
    ll mx=-1; ll dis=-1;
    table um; // (dis,sum)
    void upd(ll d, ll v){
        auto &s=um[d];
        s+=v;
        cand(mx,dis,s,d);
    }
};

ll mx=-1,t=MAXN+4;
vv g[MAXN];
ll a[MAXN];
node dfs(ll x, ll fa, ll d){
    node ans;
    ans.upd(d,a[x]);
    for(auto y:g[x])if(y!=fa){
        auto cur=dfs(y,x,d+1);
        if(SZ(ans.um)<SZ(cur.um))swap(ans,cur);
        for(auto [di,s]:cur.um){
            ans.upd(di,s);
        }
    }
    if(x!=0){
        cand(mx,t,ans.mx,ans.dis-d);
    }
    return ans;
}

int main(){
    JET
    ll n; cin>>n;
    fore(i,1,n)cin>>a[i];
    fore(i,0,n-1){
        ll u,v; cin>>u>>v; u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1,0);
    assert(mx!=-1);
    cout<<mx<<" "<<t+1<<"\n";
    return 0;
}