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
	ll T,N,V; cin>>T>>N>>V;
	ll t=rng()%T+1; cout<<t<<"\n";
	while(t--){
		ll n=rng()%(N-1)+2,m=rng()%(N-1)+2,l=rng()%V+1,f=rng()%V+1;
		if(n>m)swap(n,m);
		cout<<n<<" "<<m<<" "<<l<<" "<<f<<"\n";
	}
	return 0;
}
