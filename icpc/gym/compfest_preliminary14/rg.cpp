#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
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
	ll n=rng()%N+1; cout<<n<<"\n";
	fore(i,0,n){
		// ll r=int(rng()%(2*V+1))-V;
		// if(!r)r++;
		ll r=rng()%V+1;
		cout<<r<<" ";
	}cout<<"\n";
	fore(i,1,n){
		cout<<rng()%i+1<<" "<<i+1<<"\n";
	}
    return 0;
}