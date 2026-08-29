#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=2e5+5;
vv h[maxn]; 
ll val[maxn],F[maxn], sn[maxn],D[maxn];
ii lr[maxn];
ll dp[maxn];
ll fdp(ll u){
    ll &r=dp[u];
    if(r>=0) return r;
    r=1;
    for(auto v:h[u]) r+=fdp(v);
    return r;
}


struct fenT{
    int n; vv ft; 
    fenT(int n=0): n(n), ft(n+5,0) {}
    void pb(){ft.pb(0);n++;}
    void upd(int i0, ll v){
        for(int i=i0+1; i<=n+1; i+=i&-i) ft[i]+=v;
    }
    void ag(int l, int r, ll v){
        upd(l,v); upd(r,-v);
    }
    ll get(int i0){
        ll r=0; for(int i=i0;i; i-=i&-i)r+=ft[i];
        return r;
    }
    ll query(int i0, int j0){
        return get(j0)-get(i0);
    }
};

vector<fenT> FT;

ll ID[maxn],wh[maxn], p[maxn], uv[maxn];
ll rt;

void dfs(ll u, vv &ord, ll dir, ll d, ll id){
    ID[u]=id; wh[u]=FT[id].n; FT[id].pb();
    lr[u].fst=SZ(ord); D[u]=d;
    ord.pb(u); sn[u]=dir;
    if(SZ(h[u])&&fdp(h[u][0])<fdp(h[u][1])){
        swap(h[u][1],h[u][0]);
    }
    fore(t,0,SZ(h[u])){
        if(t) id=SZ(FT),p[id]=h[u][t], FT.pb(fenT(0)); 
        dfs(h[u][t],ord,t,d+1,id);
    }
    lr[u].snd=SZ(ord);
}



ll getsum2(ll u){
    ll r=val[u];
    for(auto v:h[u]) r+=getsum2(v);
    return r;
}



int main(){
    JET
    mset(F,-1); mset(dp,-1); mset(val,0);
    ll n,nchico; cin>>n; nchico=n;
    fore(i,0,n) cin>>val[i];
    fore(i,0,n-1){
        ll u, v; cin>>u>>v; u--,v--;
        h[n+i].pb(u); h[n+i].pb(v);
        F[u]=(n+i); F[v]=(n+i);
    }
    n=2*n-1;
    rt=n-1;
    vv ord;
    FT.pb(fenT(0)); p[0]=rt;
    dfs(rt,ord,-1,0,0);
    vv inv(n); fore(i,0,n) inv[ord[i]]=i;
    fenT ST(SZ(ord));

    auto getval=[&](ll u){
        // assert(ST.query(lr[u].fst,lr[u].snd)==getsum2(u));
        return ST.query(lr[u].fst,lr[u].snd);
    };
    auto getcmp=[&](ll u){
        return (ii){getval(u),-u};
    };
    auto getdom=[&](ll u){
        if(!SZ(h[u])) return u;
        u=-max(getcmp(h[u][0]),getcmp(h[u][1])).snd;
        return FT[ID[u]].get(wh[u]+1);
    };
    auto upd=[&](ll u, ll nval){
        ST.upd(inv[u],nval);
    };

    fore(i,0,nchico) upd(i,val[i]);
    fore(u,0,nchico) FT[ID[u]].ag(wh[u],wh[u]+1,u),uv[u]=u;
    fore(u,nchico,n){
        ll dom=getdom(u);
        // assert(dom<nchico);
        FT[ID[u]].ag(wh[u],wh[u]+1,dom);
        uv[dom]=u;
    }
    cout<<getdom(rt)+1<<"\n";
    ll q; cin>>q;
    while(q--){
        ll u, nval; cin>>u>>nval; u--;
        upd(u,nval); val[u]+=nval;
        ll dom=u,fdom=u,v=u; u=uv[dom];
        while(1){
            if(D[p[ID[v]]]>D[u]){
                FT[ID[v]].ag(0,wh[v]+1,dom-fdom);
                v=F[p[ID[v]]];
                continue;
            }
            FT[ID[v]].ag(wh[u],wh[v]+1,dom-fdom);
            v=F[u];
            if(v<0) break;
            ll ot=h[v][!sn[u]];
            fdom=FT[ID[ot]].get(wh[ot]+1);
            
            dom=getdom(v);
            u=uv[fdom];
            if(fdom!=dom){
                uv[fdom]=ot;
                uv[dom]=u;
            }
            
        }
        cout<<dom+1<<"\n";
    }

    

    return 0;
}