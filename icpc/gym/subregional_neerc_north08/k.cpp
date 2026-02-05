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
int main(){FIN;
#ifdef ONLINE_JUDGE
freopen("key.in","r",stdin);     freopen("key.out","w",stdout);
#endif
    int n,m; cin>>n>>m;
    ll a[n];
    fore(i,0,n) cin>>a[i];
    sort(a, a+n);
    vector <ll> rta;
    int T=0;
    ll u=0;
    fore(i,0,n){while(u+1<a[i]){
        if(T<m) {rta.pb(u+1); T++; u+=u+1;}
        if(T==m) {fore(z,0,m) cout<<rta[z]<<" "; return 0;} 
    }
        u+=a[i];
    }
    fore(i,0,m-T){
        rta.pb(u+1); u+=u+1;
    }
    fore(i,0,m) cout<<rta[i]<<" ";

    return 0;
    
}
