#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());


int main(){
	ll N,V; cin>>N>>V;
	int n=rng()%N+1;
	cout<<n<<"\n";
	fore(i,0,n){
		int a=rng()%V+1;
		cout<<a<<" ";
	}
	cout<<"\n";
	// fore(i,0,q){
	// 	int a=rng()%25+1;
	// 	cout<<a<<"\n";
	// }
}