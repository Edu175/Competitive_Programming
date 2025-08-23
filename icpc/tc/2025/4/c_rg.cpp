#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

vector<string> dos={
	"--",
	"->"
};

int main(){
	JET
	ll N,M; cin>>N>>M;
	ll n=rng()%(N-1)+2,m=rng()%M+1;
	cout<<"1\n";
	cout<<n<<" "<<m<<"\n";
	fore(i,0,m){
		ll u=rng()%n,v=rng()%(n-1);
		if(v>=u)v++;
		cout<<u+1<<" "<<dos[rng()%2]<<" "<<v+1<<"\n";
	}
	return 0;
}