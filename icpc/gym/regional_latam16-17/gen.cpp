#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

random_device rd;
mt19937 rng(rd());

int main(){
    JET
	ll n,q,V; cin>>n>>q>>V;
    cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<rng()%(V+1)<<" ";;cout<<"\n";
	fore(i,0,q){
		ll l=rng()%n,r=rng()%n;
		if(l>r)swap(l,r);
		ll k=rng()%(r-l+1);
		cout<<"Q "<<l+1<<" "<<r+1<<" "<<k+1<<"\n";
	}
	return 0;
}