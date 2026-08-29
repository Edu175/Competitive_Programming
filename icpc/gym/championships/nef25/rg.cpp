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
random_device rd;
mt19937 rng(rd());




int main(){
    JET 
    ll N,A;
    cin>>N>>A;
    ll n = rng()%N+1; cout<<n<<"\n";
    fore(i,0,n){
        ll l = rng()%A, r = rng()%A;
        if(l>r) swap(l,r);
        vv a;
        ll d = r-l;
		ll g=rng()%(d+1);
		d-=g;
        while(d){
            ll x = rng()%d+1;
            a.pb(x);
            d-=x;
			// cerr<<"g: "<<g<<"\n";
        }
        cout<<SZ(a)<<" "<<l<<" "<<r<<" ";
        show(a);
    }

    return 0;
}

