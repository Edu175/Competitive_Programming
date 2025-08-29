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
map<ll,vv> mp;

vv g[maxn];
ll dis[maxn];

void dfs1(ll x, ll fa){
    for(auto y:g[x])if(y!=fa){
        dis[y]=dis[x]+1;
        dfs1(y,x);
    }
}

int main(){
    JET
    ll n; cin>>n;
    fore(i,0,n) cin>>col[i];
    fore(i,0,n) mp[col[i]].pb(i);
    fore(i,0,n-1){
        ll x,y; cin>>x>>y; 
        x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    ll q; cin>>q;
    while(q--){
        ll x,y; cin>>x>>y; 
        x--,y--;
        ll r = maxn;
        for(auto x:mp[col[x]]){
            mset(dis,0);
            dfs1(x,-1);
            for(auto y:mp[col[y]]){
                r = min(r,dis[y]);
            }
        }
        cout<<r<<"\n";
    }
}