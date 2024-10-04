#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ll MAXN=4e5+5,INF=1e9+5;

ll fa[MAXN];
vector<ii>ps;
struct STree{
    vector<set<ii>>t; ll n;
    STree(ll n):t(2*n+5),n(n){}
    void upd(ll p, ii v, ll fg){//1 o 0
        for(p+=n;p>1;p>>=1){
            if(fg)t[p].insert(v);
            else t[p].erase(v);
        }
    }
    void range(ll l, ll r, ll s, ll e, ll idx){
        vector<ll>ks;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)ks.pb(l++);
            if(r&1)ks.pb(--r);
        }
        vector<ll>pop;
        for(auto k:ks){
            auto &st=t[k];
            for(auto it=st.lower_bound({s,-1});it!=st.end()&&it->fst<e;it++)
                pop.pb(it->snd);
        }
        for(auto i:pop){
            upd(ps[i].fst,{ps[i].snd,i},0);
            fa[i]=idx;
        }
    }
};
struct rec{
    ll l,r,s,e;
};
vector<ll>g[MAXN];
ll c[MAXN],sz[MAXN];
ll tot=0;
void dfs(ll x){
    c[x]=sz[x];
    for(auto y:g[x]){
        dfs(y);
        c[x]+=c[y];
    }
    tot+=c[x];
}
int main(){
    JET
    ll n,m; cin>>n>>m;
    vector<rec>ra(n,{0,0,0,0});
    vector<ii>ms(m);
    fore(i,0,n){
        cin>>ra[i].l>>ra[i].s>>ra[i].r>>ra[i].e;
        ps.pb({ra[i].l,ra[i].s});
    }
    ra.pb({-1,INF,-1,INF});
    ps.pb({ra.back().l,ra.back().s});
    n++;
    fore(i,0,m){
        cin>>ms[i].fst>>ms[i].snd;
        ps.pb(ms[i]);
    }
    for(auto i:ps)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	
    vector<ll>cx,cy;
    for(auto i:ps)cx.pb(i.fst),cy.pb(i.snd);
	for(auto i:ra)cx.pb(i.r),cy.pb(i.e);
    auto lam=[&](vector<ll> &c){
        sort(ALL(c));
        vv ci;
        fore(i,0,SZ(c)){
            if(!i||c[i]!=c[i-1])ci.pb(c[i]);
        }
        swap(c,ci);
    };
    auto idx=[&](vector<ll> &c, ll &v){
        v=lower_bound(ALL(c),v)-c.begin();
    };
    lam(cx);
    lam(cy);
    for(auto &i:ra){
        idx(cx,i.l);
        idx(cx,i.r);
        idx(cy,i.s);
        idx(cy,i.e);
    }
    for(auto &i:ps){
        idx(cx,i.fst);
        idx(cy,i.snd);
    }
    for(auto &i:ms){
        idx(cx,i.fst);
        idx(cy,i.snd);
    }
	for(auto i:cx)cout<<i<<" ";;cout<<"\n";
	for(auto i:cy)cout<<i<<" ";;cout<<"\n";
    for(auto i:ps)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
    for(auto i:ra)cout<<"("<<i.l<<","<<i.r<<"),"<<"("<<i.s<<","<<i.e<<") ";
    cout<<endl;
    ll k=SZ(ps);
	mset(fa,-1);
    STree st(k);
    fore(i,0,SZ(ps)){
        st.upd(ps[i].fst,{ps[i].snd,i},1);
    }
    fore(i,0,SZ(ra)){
        auto v=ra[i];
        st.range(v.l,v.r,v.s,v.e,i);
    }
	fore(i,0,SZ(ps))cout<<fa[i]<<" ";;cout<<"\n";
    fore(i,0,SZ(ra)){
       if(fa[i]!=-1)g[fa[i]].pb(i);
    }
    fore(i,SZ(ra),SZ(ps)){
        sz[fa[i]]++;
    }
    dfs(SZ(ra)-1);
    ll res=0;
    fore(x,0,SZ(ra)){
        res+=c[x]*(tot-c[x]);
    }
    cout<<res<<"\n";
    ld ans=ld(res)/ld(m*m);
    cout<<fixed<<setprecision(15)<<ans<<"\n";
    return 0;
}