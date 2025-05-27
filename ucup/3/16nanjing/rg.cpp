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
mt19937 rng(rd());

int main(){FIN;
	ll T,N,P; cin>>T>>N>>P;
	ll t=rng()%T+1;
	cout<<t<<"\n";
	while(t--){
		ll n=rng()%N+1,p=rng()%P+1;
		ll bef=rng()&1;
		// cout<<p<<": ";
		fore(i,0,n){
			bef^=(rng()%p>0);
			cout<<bef;
		}
		cout<<"\n";
	}
	return 0;
}
