#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
    ll n; cin>>n;
    vector<ll>ps;
    ll ni=n;
    for(ll i=2;i*i<=n;i++)if(ni%i==0){
        ps.pb(i);
        while(ni%i==0)ni/=i;
    }
    if(ni>1)ps.pb(ni);
    vector<ii>res;
    for(auto p:ps)res.pb({1,n/p});
    cout<<SZ(res)<<"\n";
    for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
    return 0;
}