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
    freopen("fenwick.in","r",stdin);     freopen("fenwick.out","w",stdout);
    #endif
    ll N,V; srand((ll)&N); cin>>N>>V;
    ll n=rand()%N+1;
    cout<<n<<"\n";
    fore(i,0,n)cout<<rand()%(2*V+1)-V<<" ";
    cout<<"\n";
    return 0;
}
