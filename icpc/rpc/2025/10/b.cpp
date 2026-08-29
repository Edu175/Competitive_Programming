#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) for(auto pera:v) cout<<pera<<" ";;cout<<endl;
#define imp2(v) for(auto [sandia,melon]:v) cout<<sandia<<","<<melon<<" ";;cout<<endl;
#define inp(v) for(auto &uva:v) cin>>uva;
#define inp2(v) for(auto &[fresa,mora]:v) cin>>fresa>>mora;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef __int128 xl;
typedef long double ld;
typedef vector<vv> mtx;
const ll maxn=2e5+10;
ll d[maxn],t[maxn];
ll n,b,_r,w;
ll dst[maxn];

typedef ll node;
ll oper(ll a, ll b){return a+b;}
#define NEUT 0
void actu(node &a, node v, bool b){
    if(b) a=v;
    else a+=v;
}
struct STree{
    int n; node _t[maxn];
    STree(int n): n(n) {}
    void init(){
        fore(i,0,n) _t[n+i]=NEUT;
        for(ll i=n-1; i>0;i--) _t[i]=oper(_t[(i<<1)],_t[(i<<1)|1]);
    }
    void upd(int p, node v,bool b){
        for(p+=n,actu(_t[p],v,b); p>1;p>>=1)p^=p&1,_t[p>>1]=oper(_t[p],_t[p^1]);
    }
    node query(int l, int r){
        node izq=NEUT,der=NEUT;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)izq=oper(izq,_t[l++]);
            if(r&1)der=oper(_t[--r],der);
        }
        return oper(izq,der);
    }
};
STree STdp(maxn), STant(maxn);

bool can(ll h){
    STdp.init();
    STant.init();
    ll l=0;
    ll acum=0;
    while(l<n){    
        ll r=l,mxt=acum,mxp=0;
        while(r<n){
            ll auxmxt=mxt;
            ll auxmxp=max(mxp,t[r]);
            ll ant=0,dp=0;
            ant=STant.query(0,t[r]);
            if(!STant.query(t[r],t[r]+1)){
                dp=STdp.query(t[r],b+1);
            }
            // if(h==17){
            //     cout<<acum<<"acum\n";
            //     cout<<auxmxp<<" "<<dst[auxmxp]<<"paradafin\n";
            //     cout<<ant<<"ant\n";
            //     cout<<dp<<"dp\n";
            //     cout<<mxt<<"mxt\n";
            // }
            auxmxt+=(ant+dp+2)*w;
            if(auxmxt+dst[auxmxp]<=h){
                mxt=auxmxt; mxp=auxmxp;
                STdp.upd(t[r],2,0);
                STant.upd(t[r],2,1);
                r++;
            }
            else break;
        }
        // if(h==17)cout<<"bondi "<<acum<<" \n";
        if(l==r) break;
        acum+=_r;
        fore(i,l,r){
            STant.upd(t[i],0,1);
            STdp.upd(t[i],0,1);
        }
        l=r;
    }
    return l==n;
}

int main(){
    JET
    cin>>n>>b>>_r>>w;
    STdp.n=b+1;
    STant.n=b+1;
    fore(i,0,b) cin>>d[i];
    fore(i,0,n) cin>>t[i];
    dst[0]=0;
    fore(i,0,b) dst[i+1]=dst[i]+d[i];
    ll l=1,r=1e18;
    while(l<=r){
        ll h=(l+r)>>1;
        if(can(h)) r=h-1;
        else l=h+1;
    }
    // cout<<can(17)<<"\n";
    cout<<l<<"\n";
    return 0;
}