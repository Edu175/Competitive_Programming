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

ll k,n,m;

bool can(ll x){
    if(x>m||x>n)return 0;
    return 2*x-1<=k;
}

int main(){FIN;
    #ifdef ONLINE_JUDGE
freopen("class.in","r",stdin);     freopen("class.out","w",stdout);
#endif
    cin>>k>>n>>m;
    ll l=0,r=n;
    while(l<=r){
        ll mid=(l+r)/2;
        if(can(mid))l=mid+1;
        else r=mid-1;
    }
    vector<vector<ll>>res(n,vector<ll>(m));
    fore(i,0,r)if(!res[i][0]){res[i][0]=1,k--;}
    fore(j,0,r)if(!res[0][j]){res[0][j]=1,k--;}
    fore(i,0,n)fore(j,0,m)if(k&&!res[i][j]){
        res[i][j]=1;
        k--;
    }
    cout<<r<<"\n";
    fore(i,0,n){
        fore(j,0,m){
            if(res[i][j])cout<<"#";
            else cout<<".";
        }
        cout<<"\n";
    }
    return 0;
}
