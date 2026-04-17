#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
int main(){JET
	ll n,k,V; cin>>n>>k>>V;
	cout<<n<<" "<<k<<"\n";
	fore(i,0,n+1)cout<<rng()%(V+1)<<" ";;cout<<"\n";
	fore(i,0,n+1)cout<<rng()%(V+1)<<" ";;cout<<"\n";
	return 0;
}