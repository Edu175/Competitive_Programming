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
vector<char> alp;

int main(){FIN;
	fore(i,'0','9'+1)alp.pb(i);
	fore(i,'A','F'+1)alp.pb(i);
	ll N,M,K; cin>>N>>M>>K;
	ll n=N,m=M,k=K;
	m=(m+3)/4*4;
	cout<<n<<" "<<m<<" "<<k<<"\n";
	fore(i,0,n){
		fore(j,0,m/4)cout<<alp[rng()%SZ(alp)];
		cout<<"\n";
	}
	return 0;
}
