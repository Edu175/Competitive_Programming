#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main(){FIN;
	ll K,N; srand((ll)&N); cin>>K>>N;
	ll k=rand()%K+1,n=rand()%N+1;
	cout<<k<<" "<<n<<"\n";
	fore(i,0,k){
		fore(j,0,k)cout<<rand()%2;
		cout<<"\n";
	}
	fore(i,0,n)cout<<char('a'+rand()%k);
	cout<<"\n";
	return 0;
}
