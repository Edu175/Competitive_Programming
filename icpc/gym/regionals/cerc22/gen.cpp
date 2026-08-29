#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());


int main(){
	JET
	ll N,Q,A; cin>>N>>Q>>A;
	ll n = rng()%N+1, q = rng()%Q+1;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n) cout<<(rng()%2 ? "":"-")<<rng()%A<<" ";
	cout<<"\n";
	fore(i,0,q){
		ll x = rng()%n+1;
		ll falta = n - x + 1;
		ll y = rng()%falta+1;
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}