#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937_64 rng(rd());

int main(){FIN;
	ll t; cin>>t; cout<<t<<"\n";
	ll N,V=1000'000'000; cin>>N;
	fore(i,0,t){
		ll n=N;
		cout<<n<<"\n";
		fore(i,0,n){
			fore(j,0,2)cout<<ll(rng()%(2*V+1))-V<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
