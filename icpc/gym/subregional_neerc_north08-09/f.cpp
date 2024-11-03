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

ll l(ll x){return x&-x;}
ll h(ll x){return __builtin_ctzll(l(x));}
ll n;
bool esfen(vector<ll>b){
    vector<ll>ret(n,0);
    fore(i,1,n+1){
        fore(j,i-l(i)+1,i+1)ret[i-1]+=b[j-1];
    }
    return ret==b;
}
int main(){FIN;
    #ifdef ONLINE_JUDGE
    freopen("fenwick.in","r",stdin);     freopen("fenwick.out","w",stdout);
    #endif
    cin>>n;
    vector<ll>a(n);
    fore(i,0,n)cin>>a[i];
    auto b=a;
    fore(k,1,n+1)if((k&1)&&k+1<=n){
        b[k-1]=0;
        fore(i,1,h(k+1)){
            b[k-1]+=a[k+1-(1ll<<i)-1];
        }
        b[k-1]=-b[k-1];
    }
    ll dif=0;
    fore(i,0,n)dif+=(a[i]!=b[i]);
    // cout<<dif<<"\n";
    // cout<<esfen(b)<<"\n";
    for(auto i:b)cout<<i<<" ";
    cout<<"\n";
    
    assert(esfen(b));
    return 0;
}
