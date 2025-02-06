#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
	ll N,V; cin>>N>>V;
	// ll n=rng()%N+1;
	ll n=N;
	cout<<n<<"\n";
	fore(i,1,n)cout<<rng()%i<<" ";;cout<<"\n";
	cout<<V<<" "<<V<<"\n";
	// cout<<rng()%(V+1)<<" "<<rng()%(V+1)<<"\n";
	return 0;
}