#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a));
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,V; cin>>N>>V;
	ll n=rng()%N+1;
	V=min(V,n);
	cout<<n<<" "<<V<<"\n";
	fore(i,0,n)cout<<rng()%V+1<<" ";;cout<<"\n";
}
