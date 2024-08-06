#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,hgfmdg=b;i<hgfmdg;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sldhg:v)cout<<sldhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,M,K; cin>>N>>M>>K;
	// ll n=rng()%(N-1)+2,m=rng()%M+1,k=rng()%K+1;
	ll n=N,m=M,k=K;
	cout<<n<<" "<<m<<" "<<k<<"\n";
	vector<ll>ws(m);
	iota(ALL(ws),1);
	shuffle(ALL(ws),rng);
	fore(i,0,m){
		ll u=rng()%n,v=rng()%(n-1);
		if(v>=u)v++;
		cout<<u+1<<" "<<v+1<<" "<<ws[i]<<"\n";
	}
	return 0;
}