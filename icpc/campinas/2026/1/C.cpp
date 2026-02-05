#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5e5;

ll to2(ll n){return n*(n-1)/2;}
ll tot;

ll uf[MAXN],c[MAXN]; // c number of special nodes
ll uf_find(ll x){
    return uf[x]<0?x:uf[x]=uf_find(uf[x]);
}
void uf_join(ll x, ll y){
    x=uf_find(x);
    y=uf_find(y);
    if(x==y)return;
    if(uf[x]>uf[y])swap(x,y);
    tot+=c[x]*c[y];
    uf[x]+=uf[y]; uf[y]=x;
    c[x]+=c[y];
    // cout<<"join "<<x<<","<<y<<": "<<to2(c[x])<<"\n";
}
int main(){
    JET
    ll n,m,k; cin>>n>>m>>k;
    vv is(n);
    fore(i,0,k){
        ll x; cin>>x; x--;
        is[x]=c[x]=1;
    }
    mset(uf,-1); tot=0;
    vector<array<ll,3>> ev;
    fore(i,0,m){
        ll u,v,w; cin>>u>>v>>w; u--,v--;
        ev.pb({w,u,v});
    }
    ll q; cin>>q;
    fore(i,0,q){
        ll t; cin>>t;
        ev.pb({t,-1,i});
    }
    sort(ALL(ev));
    reverse(ALL(ev));
    vv ans(q);
    for(auto [a,b,c]:ev){
        if(b==-1)ans[c]=tot;
        else uf_join(b,c);
    }
    for(auto i:ans)cout<<i<<"\n";
    return 0;
}
