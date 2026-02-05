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
const ll INF=1e18;

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vv p(n),q(n),a(n),b(n),c(n);
        fore(i,0,n)cin>>p[i],p[i]--;
        fore(i,0,n)cin>>q[i],q[i]--;
        fore(i,0,n)cin>>a[i];
        fore(i,0,n)cin>>b[i];
        fore(i,0,n)cin>>c[i];

        vv to(n);
        fore(i,0,n)to[p[i]]=q[i];
        vv vis(n);
        ll ans=0;
        fore(s,0,n)if(!vis[s]){
            vv A,B,C;
            for(ll x=s;!vis[x];x=to[x]){
                A.pb(a[x]);
                B.pb(b[x]);
                C.pb(c[x]);
                vis[x]=1;
            }
            ll cur=-INF;
            fore(_,0,2){
                ll m=SZ(A);
                vector<vv> dp(m+1,vv(2));
                dp[m][1]=-INF; // ult es 1
                for(ll i=m-1;i>=0;i--)fore(bo,0,2){
                    auto &res=dp[i][bo];
                    res=dp[i+1][bo]+B[i]; // 1
                    ll cost=(bo?C[i]:A[i]);
                    res=max(res,cost+dp[i+1][bo^1]); // 0 o 2
                }
                ll res=dp[0][0]; // prim es 0
                cur=max(cur,res);
                swap(A,C);
            }
            ans+=cur;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
