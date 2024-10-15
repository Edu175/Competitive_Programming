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

int a[1000009];



int main(){FIN;
#ifdef ONLINE_JUDGE
freopen("deposits.in","r",stdin);     freopen("deposits.out","w",stdout);
#endif

    int n,m; cin>>n;
    int b[n];
    fore(i,0,n)cin>>b[i];
    cin>>m;
    fore(i,0,m){
        int x; cin>>x;
        a[x]++;
    }
    ll rta=0;
    fore(i,0,n){
        for(int j=1;j*j<=b[i];j++){
            if(b[i]%j==0){
                rta+=a[j];
                if(j*j!=b[i]) rta+=a[b[i]/j];
            }
        }
        //cout<<rta<<" ";
    }
    cout<<rta<<"\n";
}
