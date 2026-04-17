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

const ll inf = 1e9;

int main(){
    JET
    ll n; cin>>n;
    ii mx = {-inf,-inf}, mn = {inf,inf};
    fore(i,0,n){
        ll x,y; cin>>x>>y;
        mx = {max(mx.fst,x+1), max({mx.snd,y+1})};
        mn = {min(mn.fst,x-1),min({mn.snd,y-1})};
    }
    cout<<(mx.fst + mx.snd - mn.fst - mn.snd)*2<<"\n";
    return 0;
}