#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,A; cin>>N>>A;
	assert(A<=20);
	ll n=rng()%N+1; cout<<n<<"\n";
	fore(i,0,n){
		ll u=-1,v=-1;
		if(i>=2&&(rng()&1)){ // comment rng?
			u=rng()%i;
			v=rng()%(i-1);
			if(v>=u)v++;
		}
		char c='a'+rng()%A;
		cout<<u+1<<" "<<v+1<<" "<<c<<"\n";
	}
	return 0;
}