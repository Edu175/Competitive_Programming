#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937_64 rng(rd());

int main(){
	JET
	ll N,M,V; cin>>N>>M>>V;
	ll n=rng()%N+1,m=rng()%(M-(n-1)+1)+1;
	cout<<n<<" "<<m<<"\n";
	fore(i,0,n){
		cout<<ll(rng()%(2*V+1))-V<<" ";
	}
	cout<<"\n";
	return 0;
}