#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szkopul=b;i<szkopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N; cin>>N;
	ll n=rng()%(N-1)+2;
	cout<<"1\n"<<n<<"\n";
	fore(i,1,n){
		ll p=rng()%i;
		ll a=p+1,b=i+1;
		if(rng()&1)swap(a,b);
		cout<<a<<" "<<b<<" "<<(rng()&1)<<"\n";
	}
	return 0;
}