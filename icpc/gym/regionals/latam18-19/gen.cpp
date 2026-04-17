#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
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
	ll N,K; cin>>N>>K;
	ll n = rng()%N;
	vv s;
	fore(i,0,n){
		ll x = rng()%K;
		if(rng()%2)x=-x;
		s.pb(x);
	}
	vv out;
	fore(i,0,1<<n){
		ll sum = 0;
		fore(j,0,n) if(i &(1<<j)) sum+=out[i]; 
	}
	sort(ALL(out),rng);
	cout<<n<<"\n";
	for(auto x:out) cout<<x<<"\n";
}