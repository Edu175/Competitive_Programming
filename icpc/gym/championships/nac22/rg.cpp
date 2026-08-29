#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
	
int main(){
	JET
	ll N,C,V; cin>>N>>C>>V;
	ll n=rng()%N+1;
	ll c=rng()%C+1;
	cout<<n<<" "<<c<<"\n";
	fore(i,0,n){
		ll t=rng()%V+1;
		ll d=rng()%t+1;
		cout<<t<<" "<<d<<"\n";
	}
	return 0;
}