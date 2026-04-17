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
const ll MAXN=14,MAXS=110;

string nu;

ll dp[MAXN][MAXS][MAXS][2];
ll pot[MAXN];
ll f(ll i, ll s, ll d, ll k, ll b){
    ll &res=dp[i][s][k][b];
    if(res!=-1)return res;
    if(i==SZ(nu))return res=(s==d&&k==0);
    ll e=b?nu[i]-'0'+1:10;
    res=0;
    fore(j,0,e)if(s+j<=d){
        res+=f(i+1,s+j,d,(k+j*pot[SZ(nu)-1-i]%d)%d,(b&&(j==e-1)));
    }
    // if(d<10&&res)cout<<d<<" "<<e<<" | "<<i<<" "<<s<<" "<<k<<" "<<b<<": "<<res<<"\n";
    return res;

}

int main(){FIN;
    #ifdef ONLINE_JUDGE
    freopen("just.in","r",stdin);     freopen("just.out","w",stdout);
    #endif
    ll n; cin>>n;
    nu=to_string(n);
    pot[0]=1;
    fore(i,1,MAXN)pot[i]=pot[i-1]*10;
    ll res=0;
    fore(d,1,MAXS){
        mset(dp,-1);
        // if(d<10)cout<<d<<"  ---d---- :   \n";
        res+=f(0,0,d,0,1);
    }
    cout<<res<<"\n";
    return 0;
}