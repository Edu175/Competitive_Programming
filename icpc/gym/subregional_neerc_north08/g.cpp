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
#ifdef ONLINE_JUDGE
freopen("deposits.in","r",stdin);     freopen("deposits.out","w",stdout);
#endif

int f (int n, int a){
    int rta=0;
    if(n==1){
        (a<45) ? rta = 1-(1/(2*tan(a))) : rta = (1/(2*tan(90-a)));
    }
    else assert(1==2);
    return rta;
}

int main(){FIN;
    int n,a;
    cin>>n>>a;
    
    return 0;
}
