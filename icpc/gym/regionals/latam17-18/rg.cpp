#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){ET;
	ll N,M,V; cin>>N>>M>>V;
	ll n=rng()%N+1;
	cout<<n<<"\n";
	fore(i,0,n){
		ll m=rng()%M+1;
		cout<<m<<" ";
		fore(j,0,m)cout<<rng()%V+1<<" ";
		cout<<"\n";
	}
}