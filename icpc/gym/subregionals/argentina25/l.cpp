#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXK=600;

int main(){
    JET
    ll n,v; cin>>n>>v;
    vv a(n);
    fore(i,0,n)cin>>a[i];
    vv sp(n+1);
    fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
    vector<vv> dp(n+1,vv(MAXK));
    for(ll i=n-1;i>=0;i--)fore(k,1,MAXK){
        auto &res=dp[i][k];
        res=dp[i+1][k];
        if(i+k<=n)res=max(res,v-(sp[i+k]-sp[i])+dp[i+k][k+1]);
    }
    cout<<dp[0][1]<<"\n";
    return 0;
}