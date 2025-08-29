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
random_device rd;
mt19937 rng(rd());

int main(){
    JET
    ll N,C; cin>>N>>C;
    ll n = rng()%N+1;
    C=min(C,n);
    cout<<n<<"\n";
    fore(i,0,n){
        cout<<rng()%C+1<<" ";
    }
    cout<<"\n";
    vector<ll> per(n);
    iota(ALL(per),0);
    shuffle(ALL(per),rng);
    vector<ii>ed;
    fore(i,1,n){
        ed.pb({per[i],per[rng()%i]});
    }
    shuffle(ALL(ed),rng);
    for(auto [x,y]:ed){
        cout<<x+1<<" "<<y+1<<"\n";
    }
    cout<<1<<"\n";
    fore(i,0,1){
        cout<<rng()%n+1<<" "<<rng()%n+1<<"\n";
    }
    return 0;
}