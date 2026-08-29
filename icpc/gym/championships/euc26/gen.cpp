#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,M,Z; cin>>N>>M>>Z;
	ll n = rng()%N+1; cout<<n<<" ";
	ll m = rng()%(min(n,M))+1; cout<<m<<" ";
	ll z = rng()%Z+1; cout<<int(1e9)<<"\n";
	set<ll> s;
	while(SZ(s) < m){
		ll x = rng()%n+1;
		s.insert(x);
	}
	show(s);
	return 0;
}