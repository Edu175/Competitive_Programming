#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());


int main(){
	JET
	ll T,N,K; cin>>T>>N>>K;
	ll t = rng()%T+1;
	cout<<t<<"\n";
	while(t--){
		ll n = rng()%N+1, k = rng()%K+1;
		while(k>=n)n = rng()%N+1, k = rng()%K+1;
		cout<<n<<" "<<k<<"\n";
		fore(i,0,n) cout<<rng()%9+1;
		cout<<"\n";
	}
	return 0;
}