#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll factorial(int n){
    // single line to find factorial
    return (n==1 || n==0) ? 1: (n * factorial(n - 1))%998244353;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<((n%2==1)?0:(factorial(n/2))*(factorial(n/2))%998244353)<<"\n";
	}
	 return 0;
}
