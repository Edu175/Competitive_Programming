#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	cout<<"1\n";
	ll N; cin>>N;
	ll n=rng()%N+1,k=rng()%n+1;
	cout<<n<<" "<<k<<"\n";
	vv per(n); iota(ALL(per),0);
	shuffle(ALL(per),rng);
	fore(i,0,n){
		cout<<per[i]+1<<" ";
	}
	cout<<"\n";
	return 0;
}
