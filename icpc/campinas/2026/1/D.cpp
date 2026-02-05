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

const ll mod=998244353;
ll mulm(ll a, ll b){return a*b%mod;}
ll addm(ll a, ll b){a+=b; return a<mod?a:a-mod;}
typedef ii node;
node oper(node a, node b){
    return {mulm(a.fst,b.fst),addm(mulm(a.snd,b.fst),b.snd)};
}
const node NEUT={1,0};
struct STree{
    int n; vector<node> t;
    STree(int n): n(n),t(2*n+5,NEUT) {}
    void init(vector<node> &a){
        fore(i,0,n) t[n+i]=a[i];
        for(ll i=n-1;i>0;i--) t[i]=oper(t[2*i],t[2*i+1]);
    }
    void upd(int p, node v){
        for(p+=n,t[p]=v; p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
    }
    node query(int l, int r){
        node izq=NEUT,der=NEUT;
        for(l+=n,r+=n; l<r; l>>=1,r>>=1){
            if(l&1) izq=oper(izq,t[l++]);
            if(r&1) der=oper(t[--r],der);
        }
        return oper(izq,der);
    }
};

int main(){
    JET
    int n; cin>>n;
    vector<node> a(n);
    a[0].fst=0;
    fore(i,0,n) cin>>a[i].snd;
    fore(i,1,n) cin>>a[i].fst;
    STree st(n);
    st.init(a);
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        l--;
        cout<<st.query(l,r).snd<<"\n";
    }
    return 0;
}
