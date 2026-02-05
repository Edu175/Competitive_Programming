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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered;


typedef ii tn;
typedef ll tl;
tn NEUT={0,0};
#define CLEAR -2
tn oper(tn a, tn b){
    return {a.fst+b.fst,a.snd+b.snd};
}
void acum(tl &a, tl v){
    // if(v==-1){a=-1;return;}
    // if(a==-2){a=v;return;}
    if(v==-2){return;}
    a=v;
}
tn calc(int s, int e, tn a, tl v){
    if(v==-1){assert(e-s==1);return {0,0};} // matado
    if(v!=-2){
        a.fst=v*a.snd;
    }
    return a;
}
struct STree{
    vector<tn> st; vector<tl> lazy; int n;
    STree(int n):st(4*n+5,NEUT), lazy(4*n+5, CLEAR),n(n){}
    void push(int k, int s, int e){
        if(lazy[k] == CLEAR) return;
        st[k] = calc(s,e,st[k],lazy[k]);
        if(e-s != 1){
            acum(lazy[2*k],lazy[k]);
            acum(lazy[2*k+1],lazy[k]);
        }
        lazy[k] = CLEAR;
    }
    void upd(int k, int s, int e, int a, int b, tl v){
        push(k,s,e);
        if(e<=a || b<=s) return;
        if(a<=s && e<=b){
            acum(lazy[k],v);
            push(k,s,e);
            return;
        }
        int m = (s+e)/2;
        upd(2*k,s,m,a,b,v); upd(2*k+1,m,e,a,b,v);
        st[k] = oper(st[2*k],st[2*k+1]);
    }
    tn query(int k, int s, int e, int a, int b){
        if(e<=a || b>=s) return NEUT;
        push(k,s,e);
        if(a<=s && e<=b) return st[k];
        int m = (s+e)/2;
        return oper(query(2*k,s,m,a,b), query(2*k+1,m,e,a,b));
    }
    void init(int k, int s, int e, vector<tn> &a){
        if(e - s == 1)st[k] = a[s];
        else{
            int m = (s+e)/2;
            init(2*k,s,m,a); init(2*k+1,m,e,a);
            st[k] = oper(st[2*k],st[2*k+1]);
        }
    }
    void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
    tn query(int a, int b){return query(1,0,n,a,b);}
    void init(vector<tn> &a){init(1,0,n,a);}
};

vv a;

struct minst{
    int n; vector<ii> t;
    minst(int n):n(n),t(2*n+5,{1e10,0}){}
    void init(vector<ii> &a){
        fore(i,0,n)t[n+i] = a[i];
        for(ll i = n-1;i>0;i--)t[i] = min(t[2*i],t[2*i+1]);
    }
    void upd(int p, ii v){
        for(p+=n, t[p] = v;p>1;p>>=1)p^=p&1,t[p>>1] = min(t[p], t[p^1]);
    }
    ii query (int l, int r){
        ii izq = {1e10,0}, der = {1e10,0};
        for(l+=n, r+=n;l<r;l>>=1,r>>=1){
            if(l&1) izq = min(izq,t[l++]);
            if(r&1)der = min(t[--r],der);
        }
        return min(izq,der);
    }
};

struct maxst{
    int n; vector<ii> t;
    maxst(int n):n(n),t(2*n+5,{0,0}){}
    void init(vector<ii> &a){
        fore(i,0,n)t[n+i] = a[i];
        for(ll i = n-1;i>0;i--)t[i] = max(t[2*i],t[2*i+1]);
    }
    void upd(int p, ii v){
        for(p+=n, t[p] = v;p>1;p>>=1)p^=p&1,t[p>>1] = max(t[p], t[p^1]);
    }
    ii query (int l, int r){
        ii izq = {0,0}, der = {0,0};
        for(l+=n, r+=n;l<r;l>>=1,r>>=1){
            if(l&1) izq = max(izq,t[l++]);
            if(r&1)der = max(t[--r],der);
        }
        return max(izq,der);
    }
};

ll res = 0;
set<ll> minis, maxis;
STree mn(n),mx(n);
minst poinmin(n);
maxst ponmax(n);
void sacarmin(int p){
    minis.erase(p);
    auto it = minis.lower_bound(p);
    ll l = p, r = *it;\
    res -= a[p] * mx.query(p+1,r).fst;
    while(l<r){
        ll aux = poinmin.query(l,r).snd;
        res += mx.query(aux,r).fst * a[aux];
        mn.upd(l,r,a[aux]);
        minis.insert(aux);
        r = aux;
    }
}

void sacarmax(int p){
    maxis.erase(p);
    auto it = maxis.lower_bound(p);
    it--;
    ll l = *it, r = p;
    res -= a[p] * mn.query(l+1,p).snd;
    while(l<r){
        ll aux = ponmax.query(l+1,r+1).snd;
        res += mn.query(l+1,aux+1).fst * a[aux];
        mx.upd(l+1,r+1,a[aux]);
        maxis.insert(aux);
        l = aux;
    }
}

int main(){
    JET
    ll n,q; cin>>n>>q;
    ordered os;
    fore(i,0,n){
        ll x; cin>>x;
        a.pb(x);
        os.insert(i);
    }
    vv mini,maxi;
    //posiblemente me conviene agregar -1/n en el los sets
    minis.insert(n); maxis.insert(-1);
    mini[0] = a[0];
    maxi[n-1] = a[n-1];
    fore(i,1,n){
        mini[i] = mini[i-1];
        if(a[i] < mini[i]){
            mini[i] = a[i];
            minis.insert(i);
        }
        maxi[i] = maxi[i+1];
        if(a[i] > maxi[i]){
            maxi[i] = a[i];
            maxis.insert(i);
        }
    }
    fore(i,0,n) res += mini[i] * maxi[i];
    mn.init(mini); mx.init(maxi);
    vector<ii> aux;
    fore(i,0,n) aux.pb({a[i],i});
    poinmin.init(aux);ponmax.init(aux);
    cout<<res<<"\n";
    while(q--){
        ll x; cin>>x;
        x--;
        x = *os.find_by_order(x);
        //transformar x con ordered set lpmmmm
        os.erase(x);
        
        auto it = maxis.lower_bound(x);
        auto it2 = minis.upper_bound(x);
        it2--;
        res-= *it * *it2;
        if(minis.count(x))sacarmin(x);
        if(maxis.count(x))sacarmax(x);
        mn.upd(x,x+1,-1);
        mx.upd(x,x+1,-1);
    }
    return 0;
}
