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
	ll N,L,K,M; cin>>N>>L>>K>>M;
	ll n=N;
	L=min(L,n);
	K=min(K,n);
	M=min(K,2*n);
	ll l=rng()%L+1;
	ll k=rng()%K+1;
	cout<<n<<" "<<l<<" "<<k<<"\n";
	fore(i,0,n)cout<<rng()%(M+1)<<" ";;cout<<"\n"; 
	return 0;
}
