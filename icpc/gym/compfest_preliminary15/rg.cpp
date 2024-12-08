#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
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
	ll n=rng()%(N-1)+2;
	cout<<n<<"\n";
	fore(i,1,n){
		ll p=rng()%i;
		cout<<p+1<<" "<<i+1<<" "<<rng()%V+1<<"\n";
	}
	ll Q; cin>>Q;
	ll q=rng()%Q+1;
	cout<<q<<"\n";
	while(q--){
		ll x=rng()%n,k=rng()%V+1;
		cout<<x+1<<" "<<k<<"\n";
	}
}