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
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

string rb="RB";

int main(){FIN;
	cout<<"1\n"; // t
	ll N,M,V; cin>>N>>M>>V;
	
	ll n=rng()%(N-1)+2, m=rng()%M+1;
	cout<<n<<" "<<m<<"\n";
	fore(i,0,m){
		ll u=rng()%n,v=rng()%(n-1);
		if(v>=u)v++;
		cout<<u+1<<" "<<v+1<<" "<< rng()%V+1<<" "<<rb[rng()&1] <<"\n";
	}
	return 0;
}
