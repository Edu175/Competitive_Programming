#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
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
    int n; cin>>n;
    ll a[n]; fore(i,0,n) cin>>a[i];
    ll i=0,r=n;
    while(i<n&&(i&1)!=(a[i]&1)) r--,i++;
    cout<<r<<"\n"; 
    return 0;
}
