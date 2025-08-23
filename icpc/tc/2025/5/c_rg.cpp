#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
const ll MAXN=1e6;
int main(){
	JET
	ll t; cin>>t;
	cout<<t<<"\n";
	ll N=MAXN/t-100,M=N;
	// ll N,M; cin>>N>>M;
	while(t--){
		ll n=rng()%N+1,m=rng()%(M-n+1)+n;
		cout<<n<<" "<<m<<"\n";
		vector<ii>ed;
		fore(i,0,m){
			if(i<n)ed.pb({i+1,i+1});
			else ed.pb({rng()%n+1,rng()%n+1});
		}
		shuffle(ALL(ed),rng);
		for(auto [x,y]:ed)cout<<x<<" "<<y<<"\n";
		cout<<"\n";
	}
	return 0;
}