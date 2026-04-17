#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll inf = 1e9+10;

int main(){
    JET
    map<ll,ll> mp1,mp2;
    ll n; cin>>n;
    vv a[2],b[2];
    fore(i,0,n){
        ll k; cin>>k;
        while(k--){
            ll x; cin>>x;
            mp1[x] ++ ;
            if(n==2) a[i].pb(x);
        }
    }
    fore(i,0,n){
        ll k; cin>>k;
        while(k--){
            ll x; cin>>x;
            mp2[x] ++;
            if(n==2) b[i].pb(x);
        }
    }
    if(n!=2){
        cout<<(mp1 == mp2 ? "S" : "N")<<"\n";
        return 0;
    }
    if(mp1 != mp2){
        cout<<"N\n";
        return 0;
    }
    ll m = inf;
    if(SZ(a[0])) m = min(m,a[0].back());
    if(SZ(a[1])) m = min(m,a[1].back());
    while(SZ(a[0]) && a[0].back() == m) a[0].pop_back();
    while(SZ(a[1]) && a[1].back() == m) a[1].pop_back();
    while(SZ(b[0]) && b[0].back() == m) b[0].pop_back();
    while(SZ(b[1]) && b[1].back() == m) b[1].pop_back();
    cout<<((a[0] == b[0] && a[1] == b[1]) ? "S" : "N")<<"\n";
    return 0;
}