#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,apio=b;i<apio;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto slkdh:v)cout<<slkdh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	ll N; srand((ll)&N); cin>>N;
	ll n=rand()%N+1;
	cout<<n<<"\n";
	fore(i,0,n)cout<<rand()%n+1<<" ";
	cout<<"\n";
	return 0;
}
