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
	ll N,M,K; cin>>N>>M>>K;
	ll n=rng()%N+1,m=rng()%(M+1),k=rng()%(K+1);
	if(n==1)m=0;
	cout<<n<<" "<<m<<" "<<k<<"\n";
	vv per(n); iota(ALL(per),0);
	shuffle(ALL(per),rng);
	fore(i,0,m){
		ll u=rng()%n,v=rng()%(n-1);
		if(v>=u)v++;
		if(u>v)swap(u,v);
		cout<<per[u]+1<<" "<<per[v]+1<<"\n";
	}
	return 0;
}
