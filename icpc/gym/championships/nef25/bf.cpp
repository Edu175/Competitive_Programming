#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size()) 
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int MAXN = 28;
ll l[MAXN], r[MAXN];
vv a[MAXN];

bool can(int i, vv ab){
    if(SZ(ab) > r[i] - l[i]) return false;
    ll x = l[i];
    ab.pb(r[i]);
    ll j = 0, k = 0;
    while(k<SZ(a[i])){
        if(x>=r[i]) return false;
        assert(x<=ab[j]);
        if(a[i][k] <= ab[j] - x){
            x+=a[i][k];
            k++;
        }
        else{
            x = ab[j]+1;
            j++;
        }
    }
    return true;
}


int main(){
    JET 
    ll n; cin>>n;
    ll le = 0,rr = MAXN*MAXN;

    fore(i,0,n){
        ll m; cin>>m>>l[i]>>r[i];
        rr = min(rr,r[i]);
        le = max(le,l[i]); 
        a[i].resize(m);
        fore(j,0,m) cin>>a[i][j];
    }
    int res = 0;
    fore(mk,1,1<<rr){
        vv ab;
        fore(i,0,MAXN)if(mk&(1<<i)) ab.pb(i);
        if(ab[0] <le || ab.back()>=rr) continue;
        bool b = true;
        fore(i,0,n)b&=can(i,ab);
        if(b) res = max(res,__builtin_popcount(mk));
        // if(b){
            // cout<<"asdiasnd ";
            // show(ab);
        // }
    }
    cout<<res<<"\n";
    return 0;
}

