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
const ll MAXMK=2e4+5;
ll pot[10];
set<ll> g[9];
ll dp[MAXMK];

ll f(ll mk, ll p, vv a){
    ll &res=dp[mk];
    if(res!=-1)return res;
    auto linea=[&](){
        ll ret=0;
        set<ll>st;
        auto mej=[&](){
            if(SZ(st)==1)ret=max(ret,*st.begin());
        };
        fore(i,0,3){
            st={a[3*i],a[3*i+1],a[3*i+2]};
            mej();
            st={a[i],a[i+3],a[i+6]};
            mej();
        }
        st={a[0],a[4],a[8]};
        mej();
        st={a[2],a[4],a[6]};
        mej();
        return ret;
    };
    // auto tablero=[&](){
    //     fore(i,0,9){
    //         cout<<a[i]<<" ";
    //         if(i%3==2)cout<<"\n";
    //     }
    // };
    ll ln=linea();
    if(ln){
        // tablero();
        // cout<<ln<<"\n\n";
        if(ln==p+1)return res=2;
        return res=0;
    }
    // ll cnt=0;
    // fore(i,0,9)cnt+=a[i]>0;
    // if(cnt==9)return res=1;
    res=2;
    ll did=0;
    fore(x,0,9)if(!a[x]){
        ll flag=1;
        for(auto y:g[x])flag&=a[y]>0;
        if(flag){
            did=1;
            auto ai=a;
            ai[x]=p+1;
            res=min(res,f(mk+(p+1)*pot[x],p^1,ai));
        }
    }
    if(!did)res=1;
    res=2-res;
    return res;
}

int main(){
    JET
    mset(dp,-1);
    pot[0]=1;
    fore(i,1,10) pot[i]=pot[i-1]*3;
    int n; cin>>n;
    fore(i,0,n){
        int x,y; cin>>x>>y;
        x--;y--;
        g[y].insert(x);
    }
    vv a(9);
    ll res=f(0,0,a);
    if(res==0)cout<<"O\n";
    if(res==1)cout<<"E\n";
    if(res==2)cout<<"X\n";
    return 0;
}