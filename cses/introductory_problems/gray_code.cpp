#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,v,n) for(ll i=v, edu=n; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	vector<string> a[n];
	a[0]={"0","1"};
	fore(i,1,n){
		fore(j,0,(1ll<<i))a[i].pb("0"+a[i-1][j]);
		for(ll j=(1ll<<i)-1; j>=0; j--)a[i].pb("1"+a[i-1][j]);
	}
	for(auto i:a[n-1])cout<<i<<"\n";
	return 0;
}
