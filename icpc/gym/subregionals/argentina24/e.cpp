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
struct arm{
    ll a,b,c;
};
ll piso(ll a, ll b){
    if(a<0)return -(abs(a)+b-1)/b;
    return a/b;
}
int main(){
    JET
    ll n,p; cin>>n>>p;
    vector<arm>a(n);
    fore(i,0,n)cin>>a[i].a>>a[i].b>>a[i].c;
    sort(ALL(a),[&](arm x, arm y){
        ll l=x.b*(y.a-1);
        ll r=y.b*(x.a-1);
        return l>r;
    });
    // for(auto i:a)cout<<i.a<<","<<i.b<<","<<i.c<<" ";;cout<<"\n";
    vector<vv>dp(n+1,vv(p+5));
    auto go=[&](ll p, arm x)->ii{
        return {piso(p-x.b,x.a),x.c};
    };
    // fore(v,0,p+1)dp[n][v]=0;
    for(ll i=n-1;i>=0;i--)fore(v,0,p+1){
        auto &res=dp[i][v];
        res=dp[i+1][v];
        auto [vi,ga]=go(v,a[i]);
        if(vi>=0)res=max(res,ga+dp[i+1][vi]);
        // cout<<i<<" "<<v<<": "<<res<<"\n";
    }
    cout<<dp[0][p]<<"\n";
    return 0;
}
/*
2 10
3 1 4
2 8 6
3,1,4 2,8,6 
6




*/