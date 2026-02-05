#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n,m,a; cin>>n>>m>>a;
        ll res;
        if(2*m<=a)res=2*m;
        else res=min(m+a/2-(a==0),n+m-1);
        cout<<res<<"\n";
    }
    return 0;
}
