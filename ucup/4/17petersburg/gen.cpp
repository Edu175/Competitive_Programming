#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());


int main(){
	ll N;  cin>>N;
	ll n = rng()%N+2;
	n*=3;
	cout<<n<<endl;
	ll p[n]; iota(p,p+n,0);
	shuffle(p,p+n,rng);
	fore(i,0,n) cout<<i+1<<" "<<p[i]+1<<"\n";
	
	
	
	return 0;
}