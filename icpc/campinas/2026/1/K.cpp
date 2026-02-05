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
typedef __int128 xl;
ll mulm(xl a, xl b, ll m){
    return a*b%m;
}
ll fp(ll b, ll e, ll m){
    ll r=1;
    while(e){
        if(e&1) r=mulm(r,b,m);
        b=mulm(b,b,m);
        e>>=1;
    }
    return r;
}
bool ipp(ll n, int a){
    if(n==a) return true;
    ll s=0,d=n-1;
    while(!(d&1))s++,d>>=1;
    ll x=fp(a,d,n);
    if((x==1)||(x+1==n)) return true;
    fore(_,0,s-1){
        x=mulm(x,x,n);
        if(x==1) return false;
        if(x+1==n) return true;
    }
    return false;
}
bool isp(ll n){
    if(n==1) return false;
    int ar[9]={2,3,5,7,11,13,17,19,23};
    fore(i,0,9)if(!ipp(n,ar[i])) return false;
    return true;
}
int main(){
    JET
    ll M=1e6+5;
    vv a;
    fore(i,2,M){
        if(isp(i)&&isp(4+i*i)){ a.pb(4+i*i);}
    }
    int q; cin>>q;
    while(q--){
        ll l,r; cin>>l>>r; r++;
        int rt=lower_bound(ALL(a),r)-lower_bound(ALL(a),l);
        cout<<rt<<"\n";
    }
    return 0;
}
