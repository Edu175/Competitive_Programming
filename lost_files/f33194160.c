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
    ll n;
    cin>>n;
    if((n*(n+1))/2%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<n/2<<endl;
    for(ll i=1;i<=n/2;i++)cout<<i<<" ";
    cout<<endl;
    cout<<n/2<<endl;
    for(ll i=n/2+1;i<=n;i++)cout<<i<<" ";
    return 0;
}

