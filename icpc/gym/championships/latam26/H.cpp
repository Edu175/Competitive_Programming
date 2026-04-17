#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet =b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) do{for(auto i:v)cout<<i<<" ";;cout<<"\n";}while(false);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}

const int LG=22;
typedef vv poly;

template<class u, class uu, u p, u root>
struct FFT{
    u r[1+(2<<LG)];
    constexpr u m(u a, u b){
        uu k=uu(a)*b;
        #define op(g) g*(g*p+2)
        k+=u(k)*(op(op(op(op(op(-p)))))) *uu(p);
        #undef op
        return u(k>>(8*sizeof(u)));
    }
    constexpr u red(u k, u a){return a-k*(a>=k);}
    FFT(){
        u k = r[2<<LG]=-p%p,b = root, e = p>>LG;
        for(;e;e/=2, b = m(b,b)) if(e&1)k = m(k,b);
        for(int  i = (2<<LG)-1;i>=0;i--) r[i] = red(p,m(r[i+1],k)),i&(i-1)?0:k=m(k,k);
    }
    poly cv(const poly &as, const poly &bs, u *v){
        int c = max(SZ(as)+SZ(bs)-1,0ll),n=1;
        assert(c<=(1<<LG));
        u h = u(uu(-p)*-p%p), a  = m(h,p/2+1),x,y;
        while(n<c)n*=2, h = red(p,m(h,a));
        fore(i,0,n){
            v[i] = i<SZ(as)?u(as[i]):0,
            v[i+n] = i <SZ(bs)?u(bs[i]):0;
        }
        for(auto s:{v,v+n})for(int j = n;j>=2;j--)for(int k = j&-j;k/=2;)fore(i,j-k,j){
            x=s[i],y=s[i-k];
            s[i-k] = red(2*p,x+y);
            s[i] = m(2*p+y-x,r[3*k-j+i]);
        }
        fore(i,0,n)v[i] = m(v[i],v[i+n]);
        fore(j,2,n+1)for(int k = 1;!(k&j);k*=2)fore(i,j-k,j){
            x=m(v[i],r[3*k+j-i]);
            y=red(2*p,v[i-k]);
            v[i-k]=x+y, v[i] = 2*p+y-x;
        }
        fore(i,0,c)v[i] = red(p,m(v[i],h));
        return poly(v,v+c);
    }
};
poly conv_small(const poly &as, const poly &bs){
    static uint32_t v[2<<LG];
    static FFT<uint32_t, uint64_t, 998244353,3> fft;
    return fft.cv(as,bs,v);
}
vv multiply2(vv a, vv b){
    vv c(SZ(a)+SZ(b)-1);
    fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
    return c;
}
vv multiply(vv a, vv b){
    // return multiply2(a,b);
    return conv_small(a,b);  // CONV SMALL
}



vector<ii> g[MAXN];

int tag[MAXN];
int fat[MAXN];
int szt[MAXN];

int calcsz(int x, int f){
    szt[x]=1;
    for(auto [y,rev]:g[x])if(y!=f&&tag[y]<0)szt[x]+=calcsz(y,x);
    return szt[x];
}

int ccnt=0;
void cdfs(int x, int f, int sz=-1){
    if(sz<0)sz=calcsz(x,-1);
    for(auto [y,rev]:g[x])if(tag[y]<0&&szt[y]*2>=sz){
        szt[x]=0; cdfs(y,f,sz); return;
    }
    tag[x]=ccnt++; fat[x]=f;
    for(auto [y,rev]:g[x])if(tag[y]<0)cdfs(y,x);
}
void centroid(){mset(tag,-1);ccnt=0;cdfs(0,-1);}

vv disj[MAXN],z[MAXN]; // disj is O(1e10), z is O(1e5)
ll sum[MAXN]; // sum is O(1e15) (actually O(1e10))
ll n;

ll dfs0(ll x, ll fa){
    ll res=1;
    fore(i,0,SZ(g[x])){
        auto [y,rev]=g[x][i];
        if(y==fa)continue;
        ll got=dfs0(y,x);
        res+=got;
        z[x][i]=got;
        z[y][rev]=n-got;
    }
    return res;
}

ll to2(ll n){return n*(n-1)/2;}
ll sq(ll n){return n*n;}
ll rt;
vv vec;
void dfs1(ll x, ll fa, ll i, ll d){
    assert(tag[x]>=tag[rt]);
    if(d>=SZ(vec))vec.resize(d+1);
    ll cur=disj[fa][i];
    cur%=MOD;
    // cerr<<x<<" "<<d<<": "<<cur<<"\n";
    vec[d]=add(vec[d],cur);
    fore(i,0,SZ(g[x])){
        auto [y,rev]=g[x][i];
        if(y==fa||!(tag[y]>=tag[rt]))continue;
        dfs1(y,x,i,d+1);
    }
}

// vv operator-(vv a, vv b){
//     vv c(max(SZ(a),SZ(b)));
//     fore(i,0,SZ(c)){
//         if(i<SZ(a))c[i]=add(c[i],a[i]);
//         if(i<SZ(b))c[i]=sub(c[i],b[i]);
//     }
//     return c;
// }
vv operator+(vv a, vv b){
    vv c(max(SZ(a),SZ(b)));
    fore(i,0,SZ(c)){
        if(i<SZ(a))c[i]=add(c[i],a[i]);
        if(i<SZ(b))c[i]=add(c[i],b[i]);
    }
    return c;
}
int main(){
    JET
    cin>>n;
    fore(i,0,n-1){
        ll u,v; cin>>u>>v; u--,v--;
        g[u].pb({v,SZ(g[v])});
        g[v].pb({u,SZ(g[u])-1});
    }
    fore(x,0,n)z[x]=disj[x]=vv(SZ(g[x]));
    dfs0(0,-1);
    centroid();
    fore(x,0,n)fore(i,0,SZ(g[x])){
        // auto [y,rev]=g[x][i];
        sum[x]+=sq(z[x][i]);
    }
    // fore(x,0,n)cerr<<x<<": "<<sum[x]<<"\n";
    fore(x,0,n)fore(i,0,SZ(g[x])){
        auto [y,rev]=g[x][i];
        auto &res=disj[x][i];
        ll sz=z[x][i];
        res=sq(sz-1)-sum[y]+sq(z[y][rev])+2*sz-1;
        // cerr<<x<<","<<y<<": "<<sz<<": "<<disj[x][i]<<endl;
        // cout<<endl;
        assert(res>=0);
    }
    // ll uno=0;
    // fore(x,0,n)for(auto y:g[x])if(x<y){
    //     ll cur=mul(disj[x][y]%MOD,disj[y][x]%MOD);
    //     uno=add(uno,cur);
    // }
    vv ans(n);
    fore(c,0,n){
        rt=c;
        // cerr<<"\n\ncentroid "<<c<<"\n";
        vector<vv> vecs;
        // vecs.pb({1}); // terminal c
        fore(i,0,SZ(g[c])){
            auto [y,rev]=g[c][i];
            if(!(tag[y]>=tag[rt]))continue;
            vec.clear();
            // cerr<<"rama "<<y<<"\n";
            dfs1(y,c,i,1);
            // imp(vec)
            // cout<<"\n";
            vecs.pb(vec);
            // with terminal
            auto p=multiply(vec,{disj[y][rev]%MOD});
            fore(d,0,min(SZ(p),n))ans[d]=add(ans[d],p[d]);
        }
        if(!SZ(vecs))continue;
        vv cur;
        vv all;
        for(auto vec:vecs){
            if(SZ(all)<SZ(vec))all.resize(SZ(vec));
            fore(i,0,SZ(vec))all[i]=add(all[i],vec[i]);
            
            auto p=multiply(vec,vec);
            if(SZ(cur)<SZ(p))cur.resize(SZ(p));
            fore(i,0,SZ(p))cur[i]=sub(cur[i],p[i]);
        }
        cur=multiply(all,all)+cur;
        fore(i,0,SZ(cur))cur[i]=mul(cur[i],(MOD+1)/2);
        
        // cerr<<"cur: ";;imp(cur)
        fore(d,0,min(SZ(cur),n))ans[d]=add(ans[d],cur[d]);


    }
    fore(i,1,n)cout<<ans[i]<<" ";;cout<<"\n";
    return 0;
}