#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,M; cin>>N>>M;
	ll n=rng()%N+1,n2=rng()%N+1;
	ll m=rng()%(min(M,n*n2))+1;
	vector<ii>ed;
	fore(i,0,n)fore(j,0,n2)ed.pb({i,j});
	random_shuffle(ALL(ed));
	cout<<n<<" "<<n2<<" "<<m<<"\n";
	fore(i,0,m){
		auto [u,v]=ed[i];
		cout<<u+1<<" "<<v+1<<" ";
		if(rng()&1)cout<<"R\n";
		else cout<<"B\n";
	}
	
	return 0;
}