#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

/*#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};*/
const ll MAXN=1e5+5;
ll a[MAXN],p[MAXN];

ll n;
//gp_hash_table <ll,ll,custom_hash> h[MAXN];
ll f(ll x, ll y){
	if(y>x)swap(x,y);
	//ll &res=h[x][y];
	//if(res!=0)return res;
	if(x==0)return /*res=*/a[x]*a[y];
	return /*res=*/a[x]*a[y]+f(p[x],p[y]);
	/*cout<<x<<" "<<y<<": "<<res<<"\n";
	return res;*/
}
int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1)cin>>p[i+1],p[i+1]--;
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
		cout<<f(x,y)<<"\n";
	}
	return 0;
}
