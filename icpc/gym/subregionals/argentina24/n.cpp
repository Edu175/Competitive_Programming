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
    ll  p[n];
    fore(i,0,n) cin>>p[i];
    sort(p,p+n);
    ll m=0;
    fore(i,0,n)fore(j,i,n){
        ll x=p[i]*p[i]+p[j]*p[j]+p[n-1]*p[n-1]-(p[i]*p[j]+p[j]*p[n-1]+p[i]*p[n-1]);
        if(x>m) m=x;
    }
    cout<<m<<"\n";
    return 0;
}