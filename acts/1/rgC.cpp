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
	ll N,X,V,Q; srand((ll)&N); cin>>N>>X>>V>>Q;
	ll n=rand()%N+1,q=rand()%Q+1;
	cout<<n<<" "<<q<<"\n";
	ll last=0;
	fore(i,0,n){
		last+=rand()%X+1;
		cout<<last<<" "<<rand()%V+1<<"\n";
	}
	while(q--){
		ll l=rand()%n,r=rand()%n;
		if(l>=r)swap(l,r);
		cout<<l+1<<" "<<r+1<<"\n";
	}
	return 0;
}
