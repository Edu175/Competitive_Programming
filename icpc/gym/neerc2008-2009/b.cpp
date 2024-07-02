#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define oper max
#define NEUT 0
struct STree{
    vector<ll>t; ll n;
    STree(ll n):t(2*n+5,NEUT),n(n){}
    void upd(ll p, ll v){ //AAADDDD
        for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
    }
    ll query(ll l, ll r){
        ll res=NEUT;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)res=oper(res,t[l++]);
            if(r&1)res=oper(res,t[--r]);
        }
        return res;
    }
};
const ll MAXN=2e5+5;
int main(){FIN;
    #ifdef ONLINE_JUDGE
    freopen("billboard.in","r",stdin);     freopen("billboard.out","w",stdout);
    #endif
    ll n,m,k; cin>>n>>m>>k;
    ll N=min(n,MAXN);
    STree st(N);
    vector<ll>a(k);
    fore(i,0,k)cin>>a[i];
    fore(i,0,N)st.upd(i,m);
    fore(i,0,k){
        ll l=0,r=N-1;
        // fore(i,0,N){
        //     cout<<st.query(i,i+1)<<" ";
        // }
        // cout<<"\n";
        while(l<=r){
            ll mid=(l+r)/2;
            if(st.query(0,mid+1)>=a[i])r=mid-1;
            else l=mid+1;
        }
        if(l<N){
            cout<<l+1<<"\n";
            st.upd(l,-a[i]);
        }
        else {
            cout<<"-1\n";
        }
    }
    return 0;
}



/*

5 5 5 
1
3 5 5 
2
3 1 5 
1
3 1 2 
1
0 1 2 
-1



*/