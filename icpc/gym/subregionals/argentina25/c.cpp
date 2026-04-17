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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
    ll n; cin>>n;
    vv a(4*n+5);
    fore(i,0,n){
        cin>>a[i];
        a[i+n]=a[i];
    }
    fore(i,0,SZ(a))a[i]+=i+1;
    // fore(i,0,2*n)cout<<a[i]<<" ";;cout<<"\n";
    map<ll,ll>mp;
    fore(i,0,n)mp[a[i]]++;
    ll res=n;
    fore(i,0,n){ // n siguientes
        res+=2*(mp[a[i]]-1);
        mp[a[i]]--;
        mp[a[i+n]]++;
    }
    cout<<res<<"\n";
    return 0;
}