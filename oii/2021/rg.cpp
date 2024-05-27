#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkjgh:v)cout<<dkjgh<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	/*ll t,h; cin>>t>>h;
	cout<<min(t,h)<<"\n";
	for(ll n=t,i=0;n>=1&&i<h;n--,i++)cout<<n<<"\n";*/
	ll N,V,Q; srand((ll)&N); cin>>N>>V>>Q;
	ll n=rand()%(N-1)+2;
	cout<<n<<"\n";
	fore(i,1,n){
		cout<<i+1<<" "<<rand()%i+1<<" "<<rand()%V+1<<"\n";
	}
	ll q=rand()%Q+1;
	cout<<q<<"\n";
	while(q--){
		cout<<rand()%n+1<<" "<<rand()%n+1<<"\n";
	}
	return 0;
}
