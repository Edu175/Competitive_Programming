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
    ll sum = (n*(n+1))/2;
    ll in;
    while(--n){
        cin>>in;
        sum -= in;
    }
    cout<<sum<<endl;
    retu