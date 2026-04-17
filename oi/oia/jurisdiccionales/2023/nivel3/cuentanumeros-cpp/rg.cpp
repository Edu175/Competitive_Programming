#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll N,V; srand((ll)&N); cin>>N>>V;
	//ll n=rand()%N+1;
	ll n=N;
	cout<<n<<"\n";
	fore(i,0,n){
		ll t=rand()%2; cout<<t<<" ";
		if(!t){
			ll a=rand()%V+1;
			ll b=rand()%V+1;
			if(a>b)swap(a,b);
			cout<<a<<" "<<b<<"\n";
		}
		else cout<<rand()%V+1<<"\n";
	}
	return 0;
}
