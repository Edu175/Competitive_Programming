#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        ll y,x;
        cin>>y>>x;
        ll mx=max(x,y);
        ll ans=mx*mx-(mx-1);
        if(mx==y){
            if(x<mx) ans-=(mx-x);
        }
        else{
            if(y<mx) ans-=(mx-y);
            ans=ans-(mx-1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

