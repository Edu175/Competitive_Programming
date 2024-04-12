#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ceoi=b;i<ceoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto kdjfhg:v)cout<<kdjfhg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll N; srand((ll)&N); cin>>N;
	ll n=rand()%N+1;
	ll q=rand()%N+1;
	if(n&1)n++;
	cout<<n<<" "<<q<<"\n";
	vector<ll>p;
	fore(i,0,n)p.pb(i);
	random_shuffle(ALL(p));
	for(auto i:p)cout<<i+1<<" ";;cout<<"\n";
	fore(i,0,q){
		ll j=rand()%n+1,t=rand()%(n+min(n+1,(ll)10));
		cout<<t<<" "<<j<<"\n";
	}
	return 0;
}
