#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	ET
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-1)+2; cout<<n<<"\n";
	auto num=[&](){return rng()%(V+1);};
	fore(i,0,n-1)cout<<num()<<" ";;cout<<"\n";
	fore(i,0,n)cout<<num()<<" ";;cout<<"\n";
	fore(i,0,n+1)cout<<num()<<" ";;cout<<"\n";
}