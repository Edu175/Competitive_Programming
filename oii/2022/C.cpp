#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size)
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll res=1;
	fore(i,1,n)res=res*i%MOD;
	cout<<res<<"\n";
	return 0;
}

/*

g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG

*/
