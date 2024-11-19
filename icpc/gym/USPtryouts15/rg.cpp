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
	ll T,N,V; cin>>T>>N>>V;
	ll t=rng()%T+1; cout<<t<<"\n";
	while(t--){
		ll n=rng()%N+1;
		cout<<n<<" "<<rng()%V<<" "<<rng()%(n+1)<<"\n";
		fore(i,0,n){
			fore(h,0,2)cout<<rng()%V<<" ";
			cout<<"\n";
		}
	}
	return 0;
}