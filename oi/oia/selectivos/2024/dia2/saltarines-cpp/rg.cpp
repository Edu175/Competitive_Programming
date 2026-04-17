#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdkjg:v)cout<<fdkjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	ll N,V; srand((ll)&N); cin>>N>>V;
	ll n=rand()%N+1;
	ll c=rand()%n+1;
	ll k=rand()%((n+1)*(n+1)/2);
	cout<<n<<" "<<k<<"\n";
	fore(i,0,n)cout<<rand()%V+1<<" ";;cout<<"\n";
	vector<ll>p;
	fore(i,0,n+1)p.pb(i);
	random_shuffle(ALL(p));
	cout<<c<<"\n";
	fore(i,0,c)cout<<p[i]<<" ";;cout<<"\n";
	return 0;
}
